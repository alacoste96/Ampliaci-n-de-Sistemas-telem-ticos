#ifndef TEMP_H
#define TEMP_H

#include "Sensor.h"

/**
 * \file Temp.h
 * \brief This file contains the declaration of the Temp class.
 */

/**
 * \class Temp
 * \brief Represents a temperature Sensor.
 * 
 * This class represents a temperature sensor, which is a type of sensor specialized in measuring temperature.
 */
class Temp: public Sensor {
public:
    /**
     * \brief Constructor for the Temp class.
     * \param id Unique identifier of the temperature sensor.
     * \param type Type of the temperature sensor.
     */
  Temp(int id = 0, int type = 0):Sensor(id, type) {
      this->type_ = TYPE_TEMP; /**< Set the sensor type to TYPE_TEMP. */
  };
};

#endif
