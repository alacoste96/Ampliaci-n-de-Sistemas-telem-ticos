#ifndef LIGHTQUALITY_H
#define LIGHTQUALITY_H

#include "Sensor.h"

class LightQuality: public Sensor {
public:
    LightQuality(int id = 0, int type = 0):Sensor(id, type){this->type_ = TYPE_LIGHT;};
};

#endif