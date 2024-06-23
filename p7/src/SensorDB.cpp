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
    std::string line, id, type;
    uint nline = 1;
    std::ifstream database("SensorDB.txt");
    
    if (!database.is_open()){
        std::cerr << "Error: Cannot open file SensorDB.txt" << std::endl;
        exit(1);
    }
    while (getline(database, line)) { // Lee línea por línea del archivo
        std::stringstream r_line(line);
        if (!getline(r_line, id, '-') || !getline(r_line, type)) {
            std::cerr << "Format error in file SensorDB.txt at line: " << nline << ". Skipping..." << std::endl;
            nline++;
            continue;
        }
        try{
            SensorDB::addSensor(stoi(type), stoi(id));
        }catch(std::exception &e){
            throw;
        }
        nline++;
    }
    database.close();
}

SensorDB::~SensorDB() {
    for (Sensor *sensor : this->sensors_) {
        delete sensor;
    }
    this->sensors_.clear();
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

int
SensorDB::getNumSens(){
    return this->sensors_[0]->getNsensors();
}

void
SensorDB::showByType(int type){
    int i;

    for(i = 0; i < SensorDB::getNumSens(); i++){
        if(sensors_[i]->getType() == type){
            sensors_[i]->showInfo();
        }
    }
}

Sensor *
SensorDB::getAsensor(int id){
    int i;

    for(i = 0; i < SensorDB::getNumSens(); i++){
        if(this->sensors_[i]->getId() == id){
            return this->sensors_[i];
        }
    }
    return nullptr;
}

int
SensorDB::getNsensByType(int type){
    int i, nsens = 0;
    for(i = 0; i < SensorDB::getNumSens(); i++){
        if(this->sensors_[i]->getType() == type){
            nsens++;
        }
    }
    return nsens;
}

void
SensorDB::showAll(){
    int i;

    for(i = 0; i < SensorDB::getNumSens(); i++){
        this->sensors_[i]->showInfo();
    }
}

int
SensorDB::getNextId(){
    int i, id = 1;

    for(i = 0; i < SensorDB::getNumSens(); i++){
        if(this->sensors_[i]->getId() > id){
            id = this->sensors_[i]->getId();
        }
    }
    return id + 1;
}


int
SensorDB::save(){
    int i;
    std::ofstream database("SensorDB.txt", std::ofstream::out | std::ofstream::trunc);

    // Verificar si el archivo se abrió correctamente
    if (!database) {
        std::cerr << "File 'SensorDB.txt' Not Found." << std::endl;
        return 0;
    }
    for (i = 0; i < SensorDB::getNumSens(); i++) {
        database << this->sensors_[i]->getId() << "-" << this->sensors_[i]->getType() << std::endl;
    }
    database.close();
    return 1;
}

void
SensorDB::showOne(int id){
    Sensor *sens = this->getAsensor(id);

    if (sens == nullptr)
        std::cout << "Sensor not found.\n";
    else 
        sens->showInfo();
}