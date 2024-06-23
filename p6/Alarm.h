#ifndef ALARM_H
#define ALARM_H

#include "SensorDB.h"

class Alarm{
private:
    bool onoff_;
    bool intrusion_;
public:
    Alarm(bool onoff = false, bool intrusion = false);
    void setOnOff(bool onoff);
    void setIntrusion(bool intrusion);
    bool getOnOff();
    bool getIntrusion();
    bool readMagSens(SensorDB *sensDB);
    void callPolice(SensorDB *sensDB);
};

#endif