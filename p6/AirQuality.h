#ifndef AIRQUALITY_H
#define AIRQUALITY_H

#include "Sensor.h"

class AirQuality: public Sensor {
public:
    AirQuality(int id = 0, int type = 0):Sensor(id, type){this->type_ = TYPE_AIR;};
};

#endif