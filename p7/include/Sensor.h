#ifndef SENSOR_H
#define SENSOR_H

#include "iostream"
#include <random>
#include <cstdlib>
#include <chrono>

/**
 * \file Sensor.h
 * \brief This file contains the declaration of the Sensor class.
 */

/**
 * \enum SensorTypes
 * \brief Enumerates different types of sensors.
 */
enum SensorTypes {
    SAMPLES_DAY = 5, /**< Number of samples per day. */
    SAMPLES_WEEK = 8, /**< Number of samples per week. */
    TYPE_TEMP = 1, /**< Temperature sensor type. */
    TYPE_HUM = 2, /**< Humidity sensor type. */
    TYPE_LIGHT = 3, /**< Light sensor type. */
    TYPE_AIR = 4, /**< Air quality sensor type. */
    TYPE_RGB = 5, /**< RGB sensor type. */
    TYPE_TERMIC = 6, /**< Termic sensor type. */
    TYPE_MAG = 7, /**< Magnetic sensor type. */
    TYPE_CAM = 8, /**< Camera sensor type. */
};

/**
 * \class Sensor
 * \brief Represents a generic sensor.
 * 
 * This class represents a generic sensor with functionality for scanning, calculating mean values,
 * generating random values, and managing sensor information.
 */
class Sensor {
protected:
    int type_; /**< Type of the sensor. */
    int id_; /**< Unique identifier of the sensor. */
    static int nsensors_; /**< Number of sensors created. */
    double *current_; /**< Array containing current sensor values. */
    double *lastDay_; /**< Array containing last day's sensor values. */
    double *lastWeek_; /**< Array containing last week's sensor values. */
public:
    /**
     * \brief Constructor for the Sensor class.
     * \param type Type of the sensor.
     * \param id Unique identifier of the sensor.
     */
    Sensor(int type = 0, int id = 0);

    /**
     * \brief Destructor for the Sensor class.
     */
    virtual ~Sensor();

    /**
     * \brief Displays information about the sensor.
     */
    virtual void showInfo();

    /**
     * \brief Scans the sensor and updates its current value.
     * \param min Minimum value for the sensor.
     * \param max Maximum value for the sensor.
     */
    void scan(double min, double max);

    /**
     * \brief Calculates the mean value of the current sensor readings.
     * \return Mean value of the current sensor readings.
     */
    double meanCurrent();

    /**
     * \brief Calculates the mean value of the sensor readings for the last day.
     * \return Mean value of the sensor readings for the last day.
     */
    double meanLastDay();

    /**
     * \brief Calculates the mean value of the sensor readings for the last week.
     * \return Mean value of the sensor readings for the last week.
     */
    double meanLastWeek();

    /**
     * \brief Generates a random value within the specified range.
     * It gets current date in microseconds as seed for the random number generator.
     * \param min Minimum value for the random value.
     * \param max Maximum value for the random value.
     * \return Random value within the specified range.
     */
    double genRand(double min, double max);
    int getType();
    int getId();
    int getNsensors();
    void setType(int type);
    void setId(int id);
    void setCurrent(double *current);
    void setLastDay(double *lastDay);
    void setLastWeek(double *lastWeek);
    double *getCurrent();
    double *getLastDay();
    double *getLastWeek();
};

#endif
