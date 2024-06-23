#include "Camera.h"

Camera::Camera(int id, int type, std::tuple<uint, uint> resolution){
  uint totres;
  uint C1, C2, C3;
  uint i;

  this->id_ = id;
  this->type_ = TYPE_CAM;
  this->resolution_ = resolution;
  totres = std::get<0>(resolution_) * std::get<1>(resolution_);
  delete [] this->current_;
  this->current_ = new double[totres];
  for(i = 0; i < totres; i+=3){
    C1 = Camera::genRand();
    C2 = Camera::genRand();
    C3 = Camera::genRand();
    this->pixel_ = std::make_tuple(C1, C2, C3);
    this->current_[i] = static_cast<double>(std::get<0>(this->pixel_));
    if (i+1 < totres) this->current_[i+1] = static_cast<double>(std::get<1>(this->pixel_));
    if (i+2 < totres) this->current_[i+2] = static_cast<double>(std::get<2>(this->pixel_));
  }
}

void
Camera::showInfo(){
  uint i, totres;

  totres = std::get<0>(resolution_) * std::get<1>(resolution_);
  switch(this->type_){
  case TYPE_RGB:
    std::cout << "Type: " << this->type_ << ". RGB Camera.\n";
    break;
  case TYPE_TERMIC:
    std::cout << "Type: " << this->type_ << ". Termic Camera.\n";
    break;
  case TYPE_CAM:
    std::cout << "Type: " << this->type_ << ". Camera.\n";
  }
  std::cout << "Id: " << this->id_ << std::endl;
  std::cout << "Current:\n[";
  for(i = 0; i < totres; i++){
    i != totres -1? std::cout << this->current_[i] << ", ": std::cout << this->current_[i] << "]\n";
  }

}

uint
Camera::genRand(){
  auto time_micros = std::chrono::duration_cast<std::chrono::microseconds>(
  std::chrono::system_clock::now().time_since_epoch()).count(); // getting time in microseconds
    
  srand(time_micros); // using current time in microseconds as seed for random generator
  uint randNum = rand() % 256;
  return randNum;
}