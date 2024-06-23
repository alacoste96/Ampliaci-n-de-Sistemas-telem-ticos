#include "DashBoard.h"

DashBoard::DashBoard(Employee *user, SensorDB *sensorDB, Alarm *alarm, UserDB *userDB) {
    this->user_ = user;
    this->option_ = 0;
    this->sensorDB_ = sensorDB;
    this->alarm_ = alarm;
    this->userDB_ = userDB;
}

DashBoard::~DashBoard() {
    delete this->sensorDB_;
}

int
DashBoard::askForOption(int max) {
    int option;

    std::cin >> option;
    if (option < 1 || option > max){
        if (std::cin.fail()) {
            // Limpiamos el estado de error de std::cin
            std::cin.clear();
            // Descartamos cualquier entrada incorrecta en el búfer
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        throw ValueError();
    }
    std::cout << std::endl;
    std::cout << "Selected option: " << option << std::endl << std::endl;
    return option;
}

void
DashBoard::showMainMenu(){
    bool numvalid = false;
    int max = 4;

    while(!numvalid){
        std::cout << "What would you like to do?" << std::endl;
        std::cout << "1. Manage Sensors." << std::endl;
        std::cout << "2. Change my password." << std::endl;
        std::cout << "3. Change user." << std::endl;
        std::cout << "4. Exit." << std::endl;
        if (this->user_->getPermission() >= 2){
            std::cout << "5. Manage Alarm." << std::endl;
            max = 5;
        }
        if (this->user_->getPermission() >= 3){
            std::cout << "6. Manage Users." << std::endl;
            max = 6;
        }
        std::cout << "Your option: ";
        try{
            this->option_ = DashBoard::askForOption(max);
            numvalid = true;
        }catch(ValueError &e){
            std::cerr << "\nInvalid number, try again(1 - " << max << ")\n\n";
        }
    }
}

void
DashBoard::showSensorsMenu(){
    bool numvalid = false;

    while(!numvalid){
        std::cout << "Manage Sensors." << std::endl;
        std::cout << "1. Add a sensor." << std::endl;
        std::cout << "2. Show all sensors." << std::endl;
        std::cout << "3. Show sensors by type." << std::endl;
        std::cout << "4. Back." << std::endl;
        std::cout << "Your option: ";
        try{
            this->option_ = DashBoard::askForOption(4);
            numvalid = true;
        }catch (ValueError &e){
            std::cout << "\nInvalid number, try again(1 - 4)\n\n";
        }
    }
}

void
DashBoard::showAllSensors(SensorDB *sensorDB){
    int i;

    for(i = 0; i < (int)sensorDB->getSensors().size(); i++){
        if (sensorDB->getSensors()[i]->getType() < TYPE_RGB){
            sensorDB->getSensors()[i]->scan(0.0, 100.0);
        }
    }
    std::cout << "\nSensors: " << std::endl;
    sensorDB->showAll();
    std::cout << std::endl;
}

int
DashBoard::selectTypeSensor(){
    bool numvalid = false;
    int type;

    while(!numvalid){
        std::cout << "Types:\n";
        std::cout << "1. Temperature.\n";
        std::cout << "2. Humidity.\n";
        std::cout << "3. Light quality.\n";
        std::cout << "4. Air Quality.\n";
        std::cout << "5. Camera RGB.\n";
        std::cout << "6. Camera Termic.\n";
        std::cout << "Your option: ";
        try{
            type = DashBoard::askForOption(6);
            numvalid = true;
        }catch (ValueError &e){
            std::cerr << "\nInvalid number, try again(1 - 6)\n\n";
        }
    }
    return type;
}

void
DashBoard::addSensor(SensorDB* sensordb){
    int type, id;

    std::cout << "Select type to add:\n";
    type = DashBoard::selectTypeSensor();
    id = sensordb->getNextId();
    sensordb->addSensor(type, id);
    std::cout << "\nSensor added." << std::endl;
}

void
DashBoard::showByType(SensorDB *sensorDB){
    int type, i;

    type = DashBoard::selectTypeSensor();
    for(i = 0; i < (int)sensorDB->getSensors().size(); i++){
        if (sensorDB->getSensors()[i]->getType() == type){
            sensorDB->getSensors()[i]->scan(0.0, 100.0);
        }
    }
    std::cout << "\nSensors of type " << type << ": " << std::endl;
    sensorDB->showByType(type);
    std::cout << std::endl;
}
int 
DashBoard::getOption() {
    return this->option_;
}  

Employee*
DashBoard::getUser() {
    return this->user_;
}