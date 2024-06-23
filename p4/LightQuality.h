#ifndef LIGHTQUALITY_H
#define LIGHTQUALITY_H

#include "Sensor.h"

class LightQuality: public Sensor {
public:
    LightQuality(int id = 0, int type = 0):Sensor(type, id){this->type_ = TYPE_LIGHT;};
};

#endif