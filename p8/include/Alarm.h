#ifndef ALARM_H
#define ALARM_H

#include "SensorDB.h"

/**
 * \file Alarm.h
 * \brief This file contains the declaration of the Alarm class.
 */

/**
 * \class Alarm
 * \brief Represents an Alarm system.
 * 
 * This class represents an alarm system with functionalities such as turning on/off the alarm,
 * detecting intrusions, reading magnetic sensors, and calling the police if necessary.
 */
class Alarm {
private:
  bool onoff_; /**< Indicates whether the alarm is turned on or off. */
  bool intrusion_; /**< Indicates whether an intrusion has been detected. */
public:
    /**
     * \brief Constructor for the Alarm class.
     * \param onoff Initial state of the alarm (true for on, false for off).
     * \param intrusion Initial state of the intrusion detection (true if intrusion detected, false otherwise).
     */
  Alarm(bool onoff = false, bool intrusion = false);

  void setOnOff(bool onoff);
  void setIntrusion(bool intrusion);
  bool getOnOff();
  bool getIntrusion();
  /**
   * \brief Displays information about the alarm like if it is turned on or off, and if an intrusion has been detected.
   * 
   * \param sensDB Pointer to the SensorDB object containing information about sensors(it will check the magnetic sensors).
   */
  void showInfo(SensorDB *sensDB);
    /**
     * \brief Reads magnetic sensors to detect intrusions.
     * \param sensDB Pointer to the SensorDB object containing information about sensors.
     * \return True if an intrusion is detected, false otherwise.
     */
  bool readMagSens(SensorDB *sensDB);

    /**
     * \brief Calls the police if an intrusion is detected.
     * \param sensDB Pointer to the SensorDB object containing information about sensors.
     */
  void callPolice(SensorDB *sensDB);
};

#endif
