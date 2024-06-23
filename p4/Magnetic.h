#ifndef MAGNETIC_H
#define MAGNETIC_H

#include "Sensor.h"

class Magnetic: public Sensor {
public:
    Magnetic(int id = 0, int type = 0):Sensor(type, id){this->type_ = TYPE_MAG;};
};

#endif