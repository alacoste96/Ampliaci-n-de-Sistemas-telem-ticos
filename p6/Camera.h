#ifndef CAMERA_H
#define CAMERA_H

#include "Sensor.h"
#include <tuple> 
#include <cstdlib>
#include <chrono>

class Camera: public Sensor {
public:
    explicit Camera(int id = 0, int type = 0, std::tuple<uint, uint> resolution = std::make_tuple(10, 10));
    void showInfo() override;
    uint genRand();
    //~Camera();// {delete [] this->current_;};
protected:
    std::tuple<uint, uint> resolution_;
    std::tuple<uint, uint, uint> pixel_;
};

#endif