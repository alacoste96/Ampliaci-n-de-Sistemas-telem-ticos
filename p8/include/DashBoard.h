#ifndef DASHBOARD_H
#define DASHBOARD_H

#include "UserDB.h"
#include "Employee.h"
#include "SensorDB.h"
#include "Alarm.h"
#include "ValueError.h"
#include "Login.h"
#include <string>
#include <set>

/**
 * \file DashBoard.h
 * \brief This file contains the declaration of the DashBoard class.
 */

/**
 * \class DashBoard
 * \brief Represents a dashboard for system management.
 * 
 * This class represents a dashboard for system management, with functionalities for displaying menus and managing sensors.
 */
class DashBoard {
private:
  Employee * user_; /**< Pointer to the logged-in user. */
  int option_; /**< Selected option in the menu. */
  SensorDB * sensorDB_; /**< Pointer to the SensorDB object. */
  Alarm * alarm_; /**< Pointer to the Alarm object. */
  UserDB * userDB_; /**< Pointer to the UserDB object. */
public:
    /**
     * \brief Constructor for the DashBoard class.
     * \param user Pointer to the logged-in user.
     * \param sensorDB Pointer to the SensorDB object.
     * \param alarm Pointer to the Alarm object.
     * \param userDB Pointer to the UserDB object.
     */
  DashBoard(Employee *user = nullptr, SensorDB *sensorDB = nullptr, Alarm *alarm = nullptr, UserDB *userDB = nullptr);

    /**
     * \brief Destructor for the DashBoard class.
     */
  ~DashBoard();

    /**
     * \brief Displays the main menu.
     */
  void showMainMenu();

    /**
     * \brief Displays the sensors menu.
     */
  void showSensorsMenu();

    /**
     * \brief Displays information about all sensors.
     * \param sensorDB Pointer to the SensorDB object.
     */
  void showAllSensors(SensorDB *sensorDB);

    /**
     * \brief Displays information about sensors of a specific type.
     * \param sensorDB Pointer to the SensorDB object.
     */
  void showByType(SensorDB *sensorDB);

    /**
     * \brief Adds a new sensor to the database.
     * \param sensorDB Pointer to the SensorDB object.
     */
  void addSensor(SensorDB *sensorDB);

    /**
     * \brief Prompts the user to select a sensor type.
     * \return Selected sensor type.
     */
  int selectTypeSensor();

  /**
     * \brief Displays the alarm menu.
     * \param alarm Reference to the Alarm object.
     */
  void showAlarmMenu(Alarm alarm);

    /**
     * \brief Changes the password of a user.
     * \param userDB Pointer to the UserDB object.
     * \param user Pointer to the Employee object representing the user.
     */
  void changePasswd(UserDB *userDB, Employee *user);

    /**
     * \brief Displays information about users by permission level.
     * \param userDB Pointer to the UserDB object.
     */
  void showByPerm(UserDB *userDB);

    /**
     * \brief Deletes a user from the database.
     * \param userDB Pointer to the UserDB object.
     */
  void delUser(UserDB *userDB);

    /**
     * \brief Displays information about all users.
     * \param userDB Pointer to the UserDB object.
     */
  void showAllUsers(UserDB *userDB);

    /**
     * \brief Adds a new user to the database.
     * \param userDB Pointer to the UserDB object.
     */
  void addUser(UserDB *userDB);

    /**
     * \brief Displays the users menu.
     */
  void showUsersMenu();

    /**
     * \brief Prompts the user to select an option.
     * \param max Maximum allowed option (between 1 and max).
     * \return Selected option.
     */
  int askForOption(int max);

    /**
     * \brief Deletes a sensor from the database.
     * \param sensorDB Pointer to the SensorDB object.
     */
  void delSensor(SensorDB *sensorDB);

    /**
     * \brief Displays the status of the alarm.
     * \param alarm Pointer to the Alarm object.
     * \param sensorDB Pointer to the SensorDB object.
     */
  void showAlarmSts(Alarm *alarm, SensorDB *sensorDB);

    /**
     * \brief Turns the alarm on or off.
     * \param alarm Pointer to the Alarm object.
     */
  void onOffAlarm(Alarm *alarm);
  int getOption();
  Employee * getUser();
  void setUser(Employee *user);
};

#endif
