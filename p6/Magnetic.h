#ifndef MAGNETIC_H
#define MAGNETIC_H

#include "Sensor.h"

class Magnetic: public Sensor {
public:
    Magnetic(int id = 0, int type = 0):Sensor(id, type){this->type_ = TYPE_MAG;this->current_[0] = 1.0;};
};

#endif