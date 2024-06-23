#ifndef RGB_H
#define RGB_H

#include "Camera.h"

class Rgb: public Camera {
public:
    Rgb(int id = 0, int type = 0, std::tuple<uint, uint> resolution = std::make_tuple(10, 10)):
        Camera(id, type, resolution){this->type_ = TYPE_RGB;};
    //~Rgb(){delete [] this->current_;};
};

#endif