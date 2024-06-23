#include "Alarm.h"

Alarm::Alarm(bool onoff, bool intrusion) {
    this->onoff_ = onoff;
    this->intrusion_ = intrusion;
}

void
Alarm::setIntrusion(bool intrusion) {
    this->intrusion_ = intrusion;
}

void
Alarm::setOnOff(bool onoff) {
    this->onoff_ = onoff;
}

bool
Alarm::getIntrusion() {
    return this->intrusion_;
}

bool
Alarm::getOnOff() {
    return this->onoff_;
}

void
Alarm::showInfo(SensorDB *sensDB) {
  Alarm::callPolice(sensDB);
  std::cout << "Alarm status: " << (this->onoff_? "ON" : "OFF") << std::endl;
  std::cout << "Intrusion hapened? " << (this->intrusion_? "YES" : "NO") << std::endl;
}

bool
Alarm::readMagSens(SensorDB *sensDB) {
  int i, nsens;

  nsens = sensDB->getNumSens();
  for(i = 0; i < nsens; i++){
    if(sensDB->getSensors()[i]->getType() == TYPE_MAG){
      if(sensDB->getSensors()[i]->getCurrent()[0] < 1.0){
        this->intrusion_ = true;
      }
    }
  }
  return this->intrusion_;
}

void
Alarm::callPolice(SensorDB *sensDB) {
  this->intrusion_ = readMagSens(sensDB);
  if(this->intrusion_){
    std::cout << "Police called!" << std::endl;
  }else{
    std::cout << "Police not called!" << std::endl;
  }
}