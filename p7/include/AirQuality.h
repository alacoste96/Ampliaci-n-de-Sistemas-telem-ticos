#ifndef AIRQUALITY_H
#define AIRQUALITY_H

#include "Sensor.h"

/**
 * \file AirQuality.h
 * \brief This file contains the declaration of the AirQuality class.
 */

/**
 * \class AirQuality
 * \brief Represents a Sensor for measuring air quality.
 * 
 * This class represents a sensor specialized in measuring air quality. It inherits from the Sensor class.
 */
class AirQuality: public Sensor {
public:
    /**
     * \brief Constructor for the AirQuality class.
     * \param id Unique identifier of the air quality sensor.
     * \param type Type of the air quality sensor.
     */
    AirQuality(int id = 0, int type = 0):Sensor(id, type) {
        this->type_ = TYPE_AIR; /**< Set the sensor type to TYPE_AIR. */
    };
};

#endif
