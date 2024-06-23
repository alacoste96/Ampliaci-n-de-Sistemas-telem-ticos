#ifndef SENSORDB_H
#define SENSORDB_H

#include "Sensor.h"
#include "Temp.h"
#include "AirQuality.h"
#include "Humidity.h"
#include "LightQuality.h"
#include "Magnetic.h"
#include "Camera.h"
#include "Termic.h"
#include "RGB.h"
#include <vector> 
#include <fstream>
#include <sstream>
#include <string>

/**
 * \file SensorDB.h
 * \brief This file contains the declaration of the SensorDB class.
 */

/**
 * \class SensorDB
 * \brief Represents a database of sensors.
 * 
 * This class represents a database of sensors, with functionalities for adding, deleting, retrieving, and displaying sensor information.
 */
class SensorDB {
private:
    std::vector<Sensor*> sensors_; /**< Vector to store pointers to Sensor objects. */
public:
    /**
     * \brief Constructor for the SensorDB class.
     */
    SensorDB();

    /**
     * \brief Destructor for the SensorDB class.
     */
    ~SensorDB();

    /**
     * \brief Retrieves the sensors of the specified type.
     * \param type Type of the sensor to retrieve.
     * \return Pointer to the first sensor of the specified type, or nullptr if not found. It allocate memory dinamically.
     */
    Sensor * getSensByType(int type);

    /**
     * \brief Retrieves a sensor with the specified ID.
     * \param id ID of the sensor to retrieve.
     * \return Pointer to the sensor with the specified ID, or nullptr if not found.
     */
    Sensor * getAsensor(int id);
    std::vector<Sensor*> getSensors();

    /**
     * \brief Retrieves the number of sensors in the database.
     * \return Number of sensors in the database.
     */
    int getNumSens();

    /**
     * \brief Retrieves the number of sensors of the specified type in the database.
     * \param type Type of sensors to count.
     * \return Number of sensors of the specified type in the database.
     */
    int getNsensByType(int type);

    /**
     * \brief Retrieves the next available ID for a new sensor.
     * \return Next available ID for a new sensor.
     */
    int getNextId();

    /**
     * \brief Saves sensor information to a file.
     * \return 0 if successful, -1 otherwise.
     */
    int save();

    /**
     * \brief Adds a new sensor to the database.
     * \param type Type of the sensor to add.
     * \param id ID of the sensor to add.
     */
    void addSensor(int type, int id);

    /**
     * \brief Displays information about all sensors in the database.
     */
    void showAll();

    /**
     * \brief Displays information about sensors of the specified type in the database.
     * \param type Type of sensors to display.
     */
    void showByType(int type);

    /**
     * \brief Displays information about the sensor with the specified ID.
     * \param id ID of the sensor to display.
     */
    void showOne(int id);
};

#endif
