#ifndef RGB_H
#define RGB_H

#include "Camera.h"

/**
 * \file Rgb.h
 * \brief This file contains the declaration of the Rgb class.
 */

/**
 * \class Rgb
 * \brief Represents an RGB Camera Sensor.
 * 
 * This class represents an RGB sensor, which is a type of camera sensor specialized in capturing RGB images.
 */
class Rgb: public Camera {
public:
    /**
     * \brief Constructor for the Rgb class.
     * \param id Unique identifier of the RGB sensor.
     * \param type Type of the RGB sensor.
     * \param resolution Resolution of the RGB sensor.
     */
  Rgb(int id = 0, int type = 0, std::tuple<uint, uint> resolution = std::make_tuple(10, 10)):
      Camera(id, type, resolution) {
      this->type_ = TYPE_RGB; /**< Set the sensor type to TYPE_RGB. */
  };
};

#endif
