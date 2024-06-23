#include "Employee.h"


Employee::Employee(int nif, int id, int permission){
  this->nif_ = nif;
  this->id_ = id;
  this->permission_ = permission;
  this->timestamp_ = std::time(0);
}

std::string
Employee::getEmployType(){
  if (this->permission_ == 1)
    return "Worker";
  else if (this->permission_ == 2)
    return "Supervisor";
  else
    return "Admin";
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
Employee::getPermission() const{
  return permission_;
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
Employee::setPermission(int permission){
  permission_ = permission;
}

void
Employee::setTimestamp(std::time_t timestamp){
  timestamp_ = timestamp;
}

void
Employee::showinfo(){
  std::cout << "NIF: " << nif_ << std::endl;
  std::cout << "ID: " << id_ << std::endl;
  std::cout << "permission: " << permission_ << std::endl;
  std::cout << "Timestamp: " << timestamp_ << std::endl;
}

bool
Employee::operator<(const Employee& right) const {
  return (this->permission_ < right.getPermission());
}

