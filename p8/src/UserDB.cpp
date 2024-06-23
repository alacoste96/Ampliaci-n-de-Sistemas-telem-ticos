#include "UserDB.h"


bool
UserDB::idExists(int id){
  for (const auto& employee: this->employees_){
    if (employee->getId() == id) {
      return true;
    }
  }
  return false;
}

bool
UserDB::nifExists(int nif){
  for (const auto& employee: this->employees_){
    if (employee->getNif() == nif) {
      return true;
    }
  }
  return false;
}
void
UserDB::loadEmployees(){
  int nif, id, permission;
  std::time_t timestamp;

  std::ifstream ifs("UserDB.dat", std::ios::in | std::ios::binary);
  if (!ifs) {
    std::ofstream ofs("UserDB.dat", std::ios::out | std::ios::binary);
    if (!ofs) {
      throw std::runtime_error("Could not open UserDB.dat");
    }
    ofs.close();
  }
  
  while(true){
    Employee* employee = new Employee();
    if (!ifs.read(reinterpret_cast<char*>(&nif), sizeof(nif))) {
      delete employee;
      break;
    }
    if (!ifs.read(reinterpret_cast<char*>(&id), sizeof(id))) {
      delete employee;
      break;
    }
    if (!ifs.read(reinterpret_cast<char*>(&permission), sizeof(permission))) {
      delete employee;
      break;
    }
    if (!ifs.read(reinterpret_cast<char*>(&timestamp), sizeof(timestamp))) {
      delete employee;
      break;
    }
    employee->setNif(nif);
    employee->setId(id);
    employee->setPermission(permission);
    employee->setTimestamp(timestamp);
    employees_.insert(employee);
  }
  ifs.close();
}

UserDB::UserDB() {
  this->num_employees_ = 0;
  this->loadEmployees();
}

void
UserDB::addUser(Employee *employee){

  std::cout << "Adding user..." << std::endl;
  employees_.insert(employee);
  num_employees_++;
}


void
UserDB::showAll(){
  std::cout << "Showing all users..." << std::endl;
  for (const auto& employee: employees_){
    employee->showinfo();
  }
}

void
UserDB::showByPerm(int permision){
  std::cout << "Showing users by permision..." << std::endl;
  for (const auto& employee: employees_){
    if (employee->getPermission() == permision){
      employee->showinfo();
    }
  }
}

void
UserDB::delUser(int index){
  std::cout << "Deleting user..." << std::endl;
  auto usertodel = employees_.begin();
  std::advance(usertodel, index);
  employees_.erase(usertodel);
  delete *usertodel;
  num_employees_--;
}

int
UserDB::saveEmployees(){
  std::ofstream ofs("UserDB.dat", std::ios::out | std::ios::binary);
  if (!ofs) {
    return 0;
  }
  int id;
  int nif;
  std::time_t timestamp;
  int permission;
  for (const auto& employee : employees_) {
    nif = employee->getNif();
    id = employee->getId();
    timestamp = employee->getTimestamp();
    permission = employee->getPermission();
    ofs.write(reinterpret_cast<const char*>(&nif), sizeof(nif));
    ofs.write(reinterpret_cast<const char*>(&id), sizeof(id));
    ofs.write(reinterpret_cast<const char*>(&permission), sizeof(permission));
    ofs.write(reinterpret_cast<const char*>(&timestamp), sizeof(timestamp));
  }
  ofs.close();
  return 1;
}

UserDB::~UserDB(){
  for (const auto& employee: employees_){
    delete employee;
  }
  employees_.clear();
}