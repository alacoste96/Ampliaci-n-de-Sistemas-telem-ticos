#include "Sensor.h"

int Sensor::nsensors_ = 0;

Sensor::Sensor(int id, int type) {
  this->type_ = type;
  this->id_ = id;
  nsensors_++;
  this->current_ = new double[1];
  this->lastDay_ = new double[SAMPLES_DAY];
  this->lastWeek_ = new double[SAMPLES_WEEK];
}

int Sensor::getNsensors() {
  return nsensors_;
}


Sensor::~Sensor() {
  delete[] this->current_;
  delete[] this->lastDay_;
  delete[] this->lastWeek_;
}

void
Sensor::showInfo(){
  int i;

  switch(this->type_){
  case(TYPE_TEMP):
    std::cout << "Type: " << this->type_ << ". Temperature.\n";
    break;
  case(TYPE_HUM):
    std::cout << "Type: " << this->type_ << ". Humidity.\n";
    break;
  case(TYPE_MAG):
    std::cout << "Type: " << this->type_ << ". Magnetic.\n";
    break;
  case(TYPE_LIGHT):
    std::cout << "Type: " << this->type_ << ". Light.\n";
    break;
  case(TYPE_AIR):
    std::cout << "Type: " << this->type_ << ". Air quality.\n";
    break;
  case(TYPE_CAM):
    std::cout << "Type: " << this->type_ << ". Camera.\n";
  }
  std::cout << "Id: " << this->id_ << std::endl;
  std::cout << "Current: " << this->current_[0] << std::endl;
  std::cout << "Last day: [";
  for(i = 0; i < SAMPLES_DAY; i++){
    i != SAMPLES_DAY -1? std::cout << this->lastDay_[i] << ", ": std::cout << this->lastDay_[i] << "]\n";
  }
  std::cout << "Last week: [";
  for(i = 0; i < SAMPLES_WEEK; i++){
    i != SAMPLES_WEEK -1? std::cout << this->lastWeek_[i] << ", ": std::cout << this->lastWeek_[i] << "]\n";
  }
}

void
Sensor::scan(double min, double max){
  int i;

  std::cout << "Scanning..." << std::endl;
  this->current_[0] = 10.0;
  for(i = 0; i < SAMPLES_DAY; i++){
    this->lastDay_[i] = Sensor::genRand(min, max);
  }
  for(i = 0; i < SAMPLES_WEEK; i++){
    this->lastWeek_[i] = Sensor::genRand(min, max);
  }
}

double
Sensor::genRand(double min, double max){
  auto time_micros = std::chrono::duration_cast<std::chrono::microseconds>(
  std::chrono::system_clock::now().time_since_epoch()).count(); // getting time in microseconds
    
  srand(time_micros); // using current time in microseconds as seed for random generator
  double randNum = min + (rand() / (double)RAND_MAX) * (max - min);
  return randNum;
}

int
Sensor::getType(){
  return this->type_;
}

int
Sensor::getId(){
  return this->id_;
}

void
Sensor::setType(int type){
  this->type_ = type;
}

void
Sensor::setId(int id){

  this->id_ = id;
}

void
Sensor::setCurrent(double *current){
  this->current_[0] = current[0];
}

void
Sensor::setLastDay(double *lastDay){
  std::cout << "Setting last day..." << std::endl;
  for(int i = 0; i < SAMPLES_DAY; i++){
    this->lastDay_[i] = lastDay[i];
  }
}

void
Sensor::setLastWeek(double *lastWeek){
  std::cout << "Setting last week..." << std::endl;
  for(int i = 0; i < SAMPLES_WEEK; i++){
    this->lastWeek_[i] = lastWeek[i];
  }
}

double *
Sensor::getCurrent(){
  return this->current_;
}

double *
Sensor::getLastDay(){
  return this->lastDay_;
}

double *
Sensor::getLastWeek(){
  return this->lastWeek_;
}





