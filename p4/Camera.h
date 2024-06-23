#ifndef CAMERA_H
#define CAMERA_H

#include "Sensor.h"
#include <tuple> 

/**
 * \brief Represents a Camera
 * 
*/
class Camera: public Sensor {
public:
    explicit Camera(int id = 0, int type = 0, std::tuple<uint, uint> resolution = std::make_tuple(10, 10));
    //~Camera();
protected:
    std::tuple<uint, uint> resolution_;
    std::tuple<uint, uint, uint> pixel_;
};

#endif