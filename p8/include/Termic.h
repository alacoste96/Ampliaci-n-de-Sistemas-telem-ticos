#ifndef TERMIC_H
#define TERMIC_H

#include "Camera.h"

/**
 * \file Termic.h
 * \brief This file contains the declaration of the Termic class.
 */

/**
 * \class Termic
 * \brief Represents a thermal Camera Sensor.
 * 
 * This class represents a thermal camera sensor, which is a type of camera sensor specialized in capturing thermal images.
 */
class Termic: public Camera {
public:
    /**
     * \brief Constructor for the Termic class.
     * \param id Unique identifier of the thermal camera sensor.
     * \param type Type of the thermal camera sensor.
     * \param resolution Resolution of the thermal camera sensor.
     */
  Termic(int id = 0, int type = 0, std::tuple<uint, uint> resolution = std::make_tuple(10, 10)):
      Camera(id, type, resolution) {
      this->type_ = TYPE_TERMIC; /**< Set the sensor type to TYPE_TERMIC. */
  };
};

#endif
