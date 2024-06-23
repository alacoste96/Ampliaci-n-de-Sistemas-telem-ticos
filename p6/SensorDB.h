#ifndef SENSORDB_H
#define SENSORDB_H

#include "Sensor.h"
#include "Temp.h"
#include "AirQuality.h"
#include "Humidity.h"
#include "LightQuality.h"
#include "Magnetic.h"
#include "Camera.h"
#include "Termic.h"
#include "RGB.h"
#include <tuple> 
#include <fstream>
#include <sstream>
#include <string>

enum{
    MAX_SENSORS = 100,
};


class SensorDB {
private:
    std::vector<Sensor*> sensors_;
public:
    SensorDB();
    ~SensorDB();
    Sensor * getSensByType(int type);
    Sensor * getAsensor(int id, int type);
    std::vector<Sensor*> getSensors();
    int getNsensByType(int type);
    void addSensor(int type, int id);
    int getNumSens();
    void showAll();
    void showByType(int type);
    void showOne(int id, int type);
};

#endif