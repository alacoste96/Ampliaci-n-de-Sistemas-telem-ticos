
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

int main()
{
  UserDB userDB = UserDB();
  Alarm alarm = Alarm();
  Employee *user;
  Admin *admin = new Admin(12345678, 12345);
  SensorDB *sensorDB;
  bool end = false, managesens = false, modedsensdb = false, authenticated = false;
  bool manageuser = false, usersmoded = false, managealarm = false;

  try
  {
    sensorDB = new SensorDB();
  }
  catch (std::bad_alloc &e)
  {
    std::cerr << "Function addsensor: Cannot allocate memory: " << e.what() << std::endl;
    std::cerr << "ERROR: Exiting" << std::endl;
    return 1;
  }
  catch (std::invalid_argument &e)
  {
    std::cerr << "Function addsensor: Invalid argument: " << e.what() << std::endl;
    std::cerr << "ERROR: Exiting" << std::endl;
    return 1;
  }
  catch (std::out_of_range &e)
  {
    std::cerr << "Function addsensor: Inserted value out of range: " << e.what() << std::endl;
    std::cerr << "ERROR: Exiting" << std::endl;
    return 1;
  }
  DashBoard dashBoard = DashBoard(nullptr, sensorDB, nullptr, &userDB);
  if(!userDB.nifExists(admin->getNif())){
    try{
      userDB.addUser(admin);
      userDB.saveEmployees();
    }
    catch (std::bad_alloc &e)
    {
      std::cout << "Cannot allocate memory: " << e.what() << std::endl;
      std::cerr << "ERROR: Exiting" << std::endl;
      userDB.saveEmployees();
      return 1;
    }
  }
  while (!authenticated)
  {
    Login login = Login();
    user = login.authenticate(&userDB);
    if(!user){
      continue;
    }
    authenticated = true;
    while (!end && authenticated)
    {
      dashBoard.setUser(user);
      dashBoard.showMainMenu();
      switch (dashBoard.getOption())
      {
      case 1:
        while (!managesens)
        {
          dashBoard.showSensorsMenu();
          switch (dashBoard.getOption())
          {
          case 1:
            try
            {
              dashBoard.addSensor(sensorDB);
            }
            catch (std::bad_alloc &e)
            {
              std::cout << "Cannot allocate memory: " << e.what() << std::endl;
              std::cerr << "ERROR: Exiting" << std::endl;
              sensorDB->save();
              return 1;
            }
            std::cout << "\nSensor added successfully\n" << std::endl;
            modedsensdb = true;
            break;
          case 2:
            dashBoard.showAllSensors(sensorDB);
            break;
          case 3:
            dashBoard.showByType(sensorDB);
            break;
          case 4:
            dashBoard.delSensor(sensorDB);
            modedsensdb = true;
            break;
          default:
            if (modedsensdb)
            {
              if (!sensorDB->save()) return 1;
              modedsensdb = false;
            }
            managesens = true;
            break;
          }
        }
        break;
      case 2:
        dashBoard.changePasswd(&userDB, user);
        usersmoded = true;
        break;
      case 3:
        authenticated = false;
        break;
      case 4:
        std::cout << "Goodbye!" << std::endl;
        end = true;
        break;
      case 5:
        while (!managealarm){
          dashBoard.showAlarmMenu(alarm);
          switch (dashBoard.getOption())
          {
          case 1:
            dashBoard.onOffAlarm(&alarm);
            break;
          case 2:
            dashBoard.showAlarmSts(&alarm, sensorDB);
            break;
          case 3:
            managealarm  = true;
            break;
          }
        }
        break;
      case 6:
        while (!manageuser){
          dashBoard.showUsersMenu();
          switch (dashBoard.getOption())
          {
          case 1:
            try{
              dashBoard.addUser(&userDB);
            }
            catch (std::bad_alloc &e)
            {
              std::cout << "Cannot allocate memory: " << e.what() << std::endl;
              std::cerr << "ERROR: Exiting" << std::endl;
              userDB.saveEmployees();
              return 1;
            }
            usersmoded = true;
            break;
          case 2:
            dashBoard.showAllUsers(&userDB);
            break;
          case 3:
            dashBoard.showByPerm(&userDB);
            break;
          case 4:
            dashBoard.delUser(&userDB);
            usersmoded = true;
            break;
          case 5:
            if (usersmoded)
            {
              if (!userDB.saveEmployees()) return 1;
              usersmoded = false;
            }
            manageuser = true;
            break;
          }
        }
        break;
      default:
        break;
      }
      managesens = false;
      manageuser = false;
      managealarm = false;
    }
  }
  return 0;
}