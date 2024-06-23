#include "DashBoard.h"

DashBoard::DashBoard(Employee *user) {
    this->user_ = user;
    this->option = 0;
}

void
DashBoard::showMainMenu(){
    std::cout << "welcome to the dashboard. Logged as: "<< this->user_->getNif() << std::endl;
    std::cout << "What would you like to do?" << std::endl;
    std::cout << "1. Manage Sensors." << std::endl;
    std::cout << "2. Change my password." << std::endl;
    std::cout << "3. Change user." << std::endl;
    std::cout << "4. Exit." << std::endl;
    if (this->user_->getPermision() >= 2){
        std::cout << "5. Manage Alarm." << std::endl;
    }
    if (this->user_->getPermision() >= 3){
        std::cout << "6. Manage Users." << std::endl;
    }
    std::cout << "Your option: ";
    std::cin >> this->option;
    std::cout << std::endl;
}

void
DashBoard::manageSensors(){
    std::cout << "Manage Sensors." << std::endl;
    std::cout << "1. Add a sensor." << std::endl;
    std::cout << "2. Show all sensors." << std::endl;
    std::cout << "3. Show sensors by type." << std::endl;
    std::cout << "Your option: ";
}