#ifndef TERMIC_H
#define TERMIC_H

#include "Camera.h"

class Termic: public Camera {
public:
    Termic(int id = 0, int type = 0, std::tuple<uint, uint> resolution = std::make_tuple(10, 10)):
        Camera(id, type, resolution){this->type_ = TYPE_TERMIC;};
    //~Termic(){delete [] this->current_;};
};

#endif