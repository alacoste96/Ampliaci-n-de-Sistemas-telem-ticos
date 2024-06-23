#ifndef MAGNETIC_H
#define MAGNETIC_H

#include "Sensor.h"

/**
 * \file Magnetic.h
 * \brief This file contains the declaration of the Magnetic class.
 */

/**
 * \class Magnetic
 * \brief Represents a magnetic Sensor.
 * 
 * This class represents a magnetic sensor, which is a type of sensor specialized in measuring magnetic fields.
 */
class Magnetic: public Sensor {
public:
    /**
     * \brief Constructor for the Magnetic class.
     * \param id Unique identifier of the magnetic sensor.
     * \param type Type of the magnetic sensor.
     */
    Magnetic(int id = 0, int type = 0):Sensor(id, type) {
        this->type_ = TYPE_MAG; /**< Set the sensor type to TYPE_MAG. */
        this->current_[0] = 1.0; /**< Set the initial current value for the magnetic sensor. */
    };
};

#endif
