#ifndef CAMERA_H
#define CAMERA_H

#include "Sensor.h"
#include <tuple> 
#include <cstdlib>
#include <chrono>

/**
 * \file Camera.h
 * \brief This file contains the declaration of the Camera class.
 */

/**
 * \class Camera
 * \brief Represents a camera Sensor.
 * 
 * This class represents a camera sensor, which is a type of sensor with resolution and pixel information.
 */
class Camera: public Sensor {
public:
    /**
     * \brief Constructor for the Camera class.
     * \param id Unique identifier of the camera sensor.
     * \param type Type of the camera sensor.
     * \param resolution Resolution of the camera sensor (width x height).
     */
    explicit Camera(int id = 0, int type = 0, std::tuple<uint, uint> resolution = std::make_tuple(10, 10));

    /**
     * \brief Displays information about the camera sensor.
     */
    void showInfo() override;

    /**
     * \brief Generates a random unsigned integer.
     * \return Random unsigned integer.
     */
    uint genRand();

protected:
    std::tuple<uint, uint> resolution_; /**< Resolution of the camera sensor (width x height). */
    std::tuple<uint, uint, uint> pixel_; /**< Pixel information (RGB) of the camera sensor. */
};

#endif
