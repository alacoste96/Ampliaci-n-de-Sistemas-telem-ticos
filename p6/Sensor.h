#ifndef SENSOR_H
#define SENSOR_H

#include "iostream"
#include <random>
#include <cstdlib>
#include <chrono>

enum{
    SAMPLES_DAY = 5, //48
    SAMPLES_WEEK = 8, //168
    TYPE_TEMP = 1,
    TYPE_HUM = 2,
    TYPE_LIGHT = 3,
    TYPE_AIR = 4,
    TYPE_MAG = 5,
    TYPE_CAM = 6,
    TYPE_RGB = 7,
    TYPE_TERMIC = 8,
};

class Sensor {
protected:
    int type_;
    int id_;
    double *current_;
    double *lastDay_;
    double *lastWeek_;
public:
    Sensor(int type = 0, int id = 0);
    virtual ~Sensor();

    virtual void showInfo();
    void scan(double min, double max);
    double meanCurrent();
    double meanLastDay();
    double meanLastWeek();
    double genRand(double min, double max);
    int getType();
    int getId();
    void setType(int type);
    void setId(int id);
    void setCurrent(double *current);
    void setLastDay(double *lastDay);
    void setLastWeek(double *lastWeek);
    double *getCurrent();
    double *getLastDay();
    double *getLastWeek();
};

#endif