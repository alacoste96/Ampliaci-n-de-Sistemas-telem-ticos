#include "Camera.h"

Camera::Camera(int id, int type, std::tuple<uint, uint> resolution){
    uint totres;
    uint C1, C2, C3;
    uint i;

    this->id_ = id;
    this->type_ = TYPE_CAM;
    this->resolution_ = resolution;
    totres = std::get<0>(resolution_) * std::get<1>(resolution_);
    std::cout << "Totres: " << totres << std::endl;
    this->current_ = new double[totres];
    for(i = 0; i < totres; i+=3){
        C1 = rand() % 255;
        C2 = rand() % 255;
        C3 = rand() % 255;
        this->pixel_ = std::make_tuple(C1, C2, C3);
        this->current_[i] = static_cast<double>(std::get<0>(this->pixel_));
        if (i+1 < totres) this->current_[i+1] = static_cast<double>(std::get<1>(this->pixel_));
        if (i+2 < totres) this->current_[i+2] = static_cast<double>(std::get<2>(this->pixel_));
        std::cout << "i: " << i << " i+1: " << i+1 << " i+2: " << i+2 << std::endl;
    }
    /*this->current_ = new double[SAMPLES_DAY];
    this->lastDay_ = new double[SAMPLES_DAY];
    this->lastWeek_ = new double[SAMPLES_WEEK];*/
}

//Camera::~Camera(){
 //   delete[] this->current_;
    /*delete[] this->lastDay_;
    delete[] this->lastWeek_;*/
//} 