#ifndef DASHBOARD_H
#define DASHBOARD_H

#include "UserDB.h"
#include "SensorDB.h"
#include "Alarm.h"
#include "ValueError.h"
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
     * \brief Prompts the user to select an option.
     * \param max Maximum allowed option(between 1 and max).
     * \return Selected option.
     */
    int askForOption(int max);
    int getOption();
    Employee * getUser();
};

#endif
