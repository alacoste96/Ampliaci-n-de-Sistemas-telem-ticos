#ifndef HUMIDITY_H
#define HUMIDITY_H

#include "Sensor.h"

/**
 * \file Humidity.h
 * \brief This file contains the declaration of the Humidity class.
 */

/**
 * \class Humidity
 * \brief Represents a humidity Sensor.
 * 
 * This class represents a humidity sensor, which is a type of sensor specialized in measuring humidity.
 */
class Humidity: public Sensor {
public:
    /**
     * \brief Constructor for the Humidity class.
     * \param id Unique identifier of the humidity sensor.
     * \param type Type of the humidity sensor.
     */
    Humidity(int id = 0, int type = 0):Sensor(id, type) {
        this->type_ = TYPE_HUM; /**< Set the sensor type to TYPE_HUM. */
    };
};

#endif
