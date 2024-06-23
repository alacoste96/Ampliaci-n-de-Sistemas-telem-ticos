
#include <iostream>
#include "include/Admin.h"
#include "include/Employee.h"
#include "include/Supervisor.h"
#include "include/Worker.h"
#include "include/UserDB.h"
#include "include/Sensor.h"
#include "include/Temp.h"
#include "include/AirQuality.h"
#include "include/Humidity.h"
#include "include/LightQuality.h"
#include "include/Magnetic.h"
#include "include/Camera.h"
#include "include/Termic.h"
#include "include/RGB.h"
#include "include/SensorDB.h"
#include "include/Alarm.h"
#include "include/Login.h"
#include "include/DashBoard.h"

int main(){
    /*Employee *employptr;
    Admin admin = Admin(234, 2);
    Admin admin2 = Admin(234, 2);
    Supervisor supervisor = Supervisor(345, 3);
    Worker worker = Worker(456, 4);
    UserDB userDB = UserDB();*/
    Employee *user;
    Admin admin = Admin(234, 2);
    user = &admin;
    SensorDB *sensorDB;
    bool end = false, managesens = false, modedsensdb = false;

    try{
        sensorDB = new SensorDB();
    } catch(std::bad_alloc &e){
        std::cerr << "Function addsensor: Cannot allocate memory: " << e.what() << std::endl;
        std::cerr << "ERROR: Exiting" << std::endl;
        return 1;
    }catch(std::invalid_argument &e){
        std::cerr << "Function addsensor: Invalid argument: " << e.what() << std::endl;
        std::cerr << "ERROR: Exiting" << std::endl;
        return 1;
    }catch(std::out_of_range &e){
        std::cerr << "Function addsensor: Inserted value out of range: " << e.what() << std::endl;
        std::cerr << "ERROR: Exiting" << std::endl;
        return 1;
    }
    DashBoard dashBoard = DashBoard(user, sensorDB);

    std::cout << "Welcome to the DashBoard. Logged as: " << user->getEmployType() << std::endl;

    while(!end){
        dashBoard.showMainMenu();
        switch(dashBoard.getOption()){
        case 1:
            while(!managesens){
                dashBoard.showSensorsMenu();
                switch(dashBoard.getOption()){
                case 1:
                    try{
                        dashBoard.addSensor(sensorDB);
                    }catch (std::bad_alloc &e){
                        std::cout << "Cannot allocate memory: " << e.what() << std::endl;
                        std::cerr << "ERROR: Exiting" << std::endl;
                        sensorDB->save();
                        return 1;
                    }
                    modedsensdb = true;
                    break;
                case 2:
                    dashBoard.showAllSensors(sensorDB);
                    break;
                case 3:
                    dashBoard.showByType(sensorDB);
                    break;
                default:
                    managesens = true;
                }
            }
        case 2:
            break;
        case 3:
            break;
        case 4:
            end = true;
            break;
        case 5:
            break;
        case 6:
            break;
        default:
            break;
        }
        managesens = false;
        if (modedsensdb){
            if(!sensorDB->save()){
                return 1;
            }
            modedsensdb = false;
        }
    }
    return 0;
}