#include "SensorDB.h"

void
SensorDB::addSensor(int type, int id){
    Sensor *sensorptr;

    switch(type) {
    case TYPE_TEMP:
        sensorptr = new Temp(id, type);
        break;
    case TYPE_HUM:
        sensorptr = new Humidity(id, type);
        break;
    case TYPE_LIGHT:
        sensorptr = new LightQuality(id, type);
        break;
    case TYPE_AIR:
        sensorptr = new AirQuality(id, type);
        break;
    case TYPE_MAG:
        sensorptr = new Magnetic(id, type);
        break;
    case TYPE_CAM:
        sensorptr = new Camera(id, type);
        break;
    case TYPE_RGB:
        sensorptr = new Rgb(id, type);
        break;
    default:
        sensorptr = new Termic(id, type);
    }
    this->sensors_.push_back(sensorptr);
}

SensorDB::SensorDB() {
    std::string line;

    std::ifstream database("SensorDB.txt");
    while (getline(database, line)) { // Lee línea por línea del archivo
        std::stringstream r_line(line);
        std::string id, type;
            
        // Extrae el ID y el tipo de la línea
        getline(r_line, id, '-');
        getline(r_line, type);
        try{
            SensorDB::addSensor(stoi(type), stoi(id));
        }catch(std::bad_alloc &e){
            std::cout << "Error: " << e.what() << std::endl;
            exit(1);
        }
    }
    database.close();
}

SensorDB::~SensorDB() {
    for (Sensor *sensor : this->sensors_) {
        delete sensor;
    }
    this->sensors_.clear();
}

int
SensorDB::getNumSens(){
    return (int)this->sensors_.size();
}

Sensor*
SensorDB::getSensByType(int type){
    int i, j, nsens;
    Sensor* senslist;

    nsens = SensorDB::getNsensByType(type);
    senslist = new Sensor[nsens]; // allocating memory for that number
    j = 0;
    for(i = 0; i < (int)this->sensors_.size(); i++){ // getting sens of that type
        if(this->sensors_[i]->getType() == type){
            senslist[j] = *this->sensors_[i];
            j++;
        }
    }
    return senslist;
}

std::vector<Sensor*>
SensorDB::getSensors(){
    return this->sensors_;
}

void
SensorDB::showByType(int type){
    int i;

    for(i = 0; i < (int)this->sensors_.size(); i++){
        if(sensors_[i]->getType() == type){
            sensors_[i]->showInfo();
        }
    }
}

Sensor *
SensorDB::getAsensor(int id, int type){
    int i;

    for(i = 0; i < (int)this->sensors_.size(); i++){
        if(this->sensors_[i]->getId() == id && this->sensors_[i]->getType() == type){
            return this->sensors_[i];
        }
    }
    return nullptr;
}

int
SensorDB::getNsensByType(int type){
    int i, nsens = 0;
    for(i = 0; i < (int)this->sensors_.size(); i++){
        if(this->sensors_[i]->getType() == type){
            nsens++;
        }
    }
    return nsens;
}

void
SensorDB::showAll(){
    int i;

    for(i = 0; i < (int)this->sensors_.size(); i++){
        this->sensors_[i]->showInfo();
    }
}


void
SensorDB::showOne(int id, int type){
    Sensor *sens = this->getAsensor(id, type);

    if (sens == nullptr)
        std::cout << "Sensor not found.\n";
    else 
        sens->showInfo();
}