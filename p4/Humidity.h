#ifndef HUMIDITY_H
#define HUMIDITY_H

#include "Sensor.h"

class Humidity: public Sensor {
public:
    Humidity(int id = 0, int type = 0):Sensor(type, id){this->type_ = TYPE_HUM;};
};

#endif