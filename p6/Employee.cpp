#include "Employee.h"


Employee::Employee(int nif, int id, int permision){
    this->nif_ = nif;
    this->id_ = id;
    this->permision_ = permision;
    this->timestamp_ = std::time(0);
}

int
Employee::getNif() const{
    return nif_;
}

int
Employee::getId() const{
    return id_;
}

int
Employee::getPermision(){
    return permision_;
}

std::time_t
Employee::getTimestamp(){
    return timestamp_;
}

void
Employee::setNif(int nif){
    nif_ = nif;
}

void
Employee::setId(int id){
    id_ = id;
}

void
Employee::setPermision(int permision){
    permision_ = permision;
}

void
Employee::setTimestamp(std::time_t timestamp){
    timestamp_ = timestamp;
}

void
Employee::showinfo(){
    std::cout << "NIF: " << nif_ << std::endl;
    std::cout << "ID: " << id_ << std::endl;
    std::cout << "Permision: " << permision_ << std::endl;
    std::cout << "Timestamp: " << timestamp_ << std::endl;
}

bool
Employee::operator<(const Employee& right) const {
    return (this->id_ < right.getId());
}

