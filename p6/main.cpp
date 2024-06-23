
#include <iostream>
#include "Admin.h"
#include "Employee.h"
#include "Supervisor.h"
#include "Worker.h"
#include "UserDB.h"
#include "Sensor.h"
#include "Temp.h"
#include "AirQuality.h"
#include "Humidity.h"
#include "LightQuality.h"
#include "Magnetic.h"
#include "Camera.h"
#include "Termic.h"
#include "RGB.h"
#include "SensorDB.h"
#include "Alarm.h"
#include "Login.h"

int main(){
    /*Employee *employptr;
    Admin admin = Admin(234, 2);
    Admin admin2 = Admin(234, 2);
    Supervisor supervisor = Supervisor(345, 3);
    Worker worker = Worker(456, 4);
    UserDB userDB = UserDB();*/
    SensorDB sensorDB = SensorDB();
    int i;

    for(i = 0; i < (int)sensorDB.getSensors().size(); i++){
        if (sensorDB.getSensors()[i]->getType() < TYPE_CAM){
            sensorDB.getSensors()[i]->scan(0.0, 100.0);
        }
    }
    sensorDB.showAll();
    //sensorDB.showByType(TYPE_TEMP);
    /*employptr = &admin;
    userDB.addUser(employptr);

    employptr = &worker;
    userDB.addUser(employptr);

    employptr = &supervisor;
    userDB.addUser(employptr);

    employptr = &admin2;
    userDB.addUser(employptr);

    userDB.showAll();

    Login login = Login();
    login.authenticate(&userDB);*/
    
/*
    std::cout << "num sensors: " << sensorDB.getNumSens() << std::endl;
    std::cout << "num sensors of type temperature: " << sensorDB.getNsensByType(TYPE_TEMP) << std::endl;
    std::cout << "num sensors of type humidity: " << sensorDB.getNsensByType(TYPE_HUM) << std::endl;
    std::cout << "num sensors of type air quality: " << sensorDB.getNsensByType(TYPE_AIR) << std::endl;*/

    //sensorDB.showAll();
    //sensorDB.showByType(TYPE_TEMP);

    //std::cout << "Hello there 3\n";
    /*sensorDB.showByType(TYPE_AIR);*/


    /*std::cout << "Employee: " << std::endl;
    empleado.showinfo();*/
/*
    std::cout << "Admin: " << std::endl;
    admin.showinfo();

    std::cout << "Admin2: " << std::endl;
    admin2.showinfo();

    std::cout << "Supervisor: " << std::endl;
    supervisor.showinfo();

    std::cout << "Worker: " << std::endl;
    worker.showinfo();

    std::cout << "UserDB: " << std::endl;

    userDB.showByPerm(3);
    userDB.modUser(2, &admin);*/
/*
    std::cout << "Temp: " << std::endl;
    temp.scan(20.0, 24.0);
    temp.showInfo();

    std::cout << "AirQuality: " << std::endl;
    airQuality.scan(20.0, 24.0);
    airQuality.showInfo();

    std::cout << "Humidity: " << std::endl;
    humidity.scan(20.0, 24.0);
    humidity.showInfo();

    std::cout << "LightQuality: " << std::endl;
    lightQuality.scan(20.0, 24.0);
    lightQuality.showInfo();

    std::cout << "Magnetic: " << std::endl;
    magnetic.scan(20.0, 24.0);
    magnetic.showInfo();
    camera.showInfo();
    termic.showInfo();
    rgb.showInfo();*/
    return 0;
}