#ifndef TEMP_H
#define TEMP_H

#include "Sensor.h"

class Temp: public Sensor {
public:
    Temp(int id = 0, int type = 0):Sensor(type, id){this->type_ = TYPE_TEMP;};
};

#endif