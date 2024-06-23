#ifndef SENSOR_H
#define SENSOR_H

#include "iostream"
#include <random>

/**
 * @{ \name Constants.
 */
/**
 * \brief Constants.
 *
 * Constants of types of Sensors and number of samples.
 */
enum{
    SAMPLES_DAY = 48,
    SAMPLES_WEEK = 168,
    TYPE_TEMP = 1,
    TYPE_HUM = 2,
    TYPE_MAG = 3,
    TYPE_LIGHT = 4,
    TYPE_AIR = 5,
    TYPE_CAM = 6
};
/**
 * @}
 */

/**
 * \brief Represents a Sensor
 * 
 * 
*/

class Sensor {
protected:
    int type_;
    int id_;
    double *current_;
    double *lastDay_;
    double *lastWeek_;
public:
    Sensor(int type = 0, int id = 0);
    ~Sensor();

    void showInfo();
    void scan(double min, double max);
    double meanCurrent();
    double meanLastDay();
    double meanLastWeek();
    double genRandDouble(double min, double max);
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