#ifndef LIGHTQUALITY_H
#define LIGHTQUALITY_H

#include "Sensor.h"

/**
 * \file LightQuality.h
 * \brief This file contains the declaration of the LightQuality class.
 */

/**
 * \class LightQuality
 * \brief Represents a light quality Sensor.
 * 
 * This class represents a light quality sensor, which is a type of sensor specialized in measuring light quality.
 */
class LightQuality: public Sensor {
public:
    /**
     * \brief Constructor for the LightQuality class.
     * \param id Unique identifier of the light quality sensor.
     * \param type Type of the light quality sensor.
     */
  LightQuality(int id = 0, int type = 0):Sensor(id, type) {
      this->type_ = TYPE_LIGHT; /**< Set the sensor type to TYPE_LIGHT. */
  };
};

#endif
