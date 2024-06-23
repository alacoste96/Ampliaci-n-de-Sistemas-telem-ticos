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

void DashBoard::showAllUsers(UserDB *userDB) {
  std::cout << "All users:" << std::endl;
  for (auto const& employee: userDB->getEmployees()) {
    employee->showinfo();
  }
  std::cout << std::endl;
}

void
DashBoard::setUser(Employee *user) {
  this->user_ = user;
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
DashBoard::delUser(UserDB *userDB) {
  bool valid = false;
  int i, nif;

  while(!valid){
    i = 1;
    std::cout << "NIFs to delete:\n";
    for (auto const& employee: userDB->getEmployees()) {
      std::cout << i << ". " << employee->getNif() << std::endl;
      i++;
    }
    try{
      std::cout << "Select the NIF of the user to delete: ";
      nif = DashBoard::askForOption(i - 1);
      valid = true;
    }catch(ValueError &e){
      std::cerr << "\nInvalid number, try again(1 - " << i - 1 << ")\n\n";
    }
  }
  userDB->delUser(nif - 1);
}

void
DashBoard::showByPerm(UserDB *userDB) {
  bool valid = false;
  int permission;

  while(!valid){
    std::cout << "Enter the permission level: ";
    try{
      permission = DashBoard::askForOption(3);
      valid = true;
    }catch(ValueError &e){
      std::cerr << "\nInvalid number, try again(1 - 3)\n\n";
    }
  }
  for (auto const& employee: userDB->getEmployees()) {
    if (employee->getPermission() == permission){
      employee->showinfo();
    }
  }
  std::cout << std::endl;
}

void
DashBoard::showUsersMenu(){
  bool numvalid = false;
  int max = 5;
  std::cout << "What would you like to do?" << std::endl;
  while(!numvalid){
    std::cout << "1. Add user." << std::endl;
    std::cout << "2. Show all users." << std::endl;
    std::cout << "3. Show users by permission." << std::endl;
    std::cout << "4. Delete user." << std::endl;
    std::cout << "5. Save and Back." << std::endl;
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
DashBoard::changePasswd(UserDB *userDB, Employee *user) {
  bool valid = false;
  int oldpasswd, newpasswd;

  while(!valid){
    std::cout << "Enter your current password: ";
    try{
      oldpasswd = DashBoard::askForOption(99999);
    }catch(ValueError &e){
      std::cerr << "\nInvalid number, try again\n\n";
      continue;
    }
    if(user->getId() == oldpasswd){
      valid = true;
    }else{
      std::cerr << "\nInvalid number, try again\n\n";
    }
  }
  valid = false;
  while(!valid){
    std::cout << "Enter your new password: ";
    try{
      newpasswd = DashBoard::askForOption(99999);
      valid = true;
    }catch(ValueError &e){
      std::cerr << "\nInvalid number, try again\n\n";
    }
  }
  for(auto const& employee: userDB->getEmployees()){
    if (employee->getNif() == user->getNif()){
      employee->setId(newpasswd);
      break;
    }
  }
  std::cout << "Password changed successfully.\n" << std::endl;
}

void
DashBoard::showMainMenu(){
  bool numvalid = false;
  int max = 4;

  std::cout << "Welcome to the DashBoard. Logged as: " << user_->getEmployType() << std::endl;
  while(!numvalid){
    std::cout << "What would you like to do?" << std::endl;
    std::cout << "1. Manage Sensors." << std::endl;
    std::cout << "2. Change my password." << std::endl;
    std::cout << "3. Log out." << std::endl;
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
    std::cout << "4. Delete a sensor." << std::endl;
    std::cout << "5. Save and go back." << std::endl;
    std::cout << "Your option: ";
    try{
      this->option_ = DashBoard::askForOption(5);
      numvalid = true;
    }catch (ValueError &e){
      std::cout << "\nInvalid number, try again(1 - 5)\n\n";
    }
  }
}

void
DashBoard::addUser(UserDB *userDB){
  int nif;
  int password;
  int permission;
  bool valid = false;
  Employee *newuser;

  while(!valid){
    std::cout << "Insert NIF: ";
    try{
      nif = DashBoard::askForOption(99999999);
      if(userDB->nifExists(nif)){
        std::cout << "NIF already exists, try again: ";
      }else{
        valid = true;
      }
    }catch(ValueError &e){
      std::cout << "\nInvalid number, try again\n\n";
    }
  }
  valid = false;
  while(!valid){
    std::cout << "Insert password: ";
    try{
      password = DashBoard::askForOption(99999);
      if(userDB->idExists(password)){
        std::cout << "Invalid password, try again: ";
      }else{
        valid = true;
      }
    }catch(ValueError &e){
      std::cout << "\nInvalid number, try again\n\n";
    }
  }
  valid = false;
  while(!valid){
    std::cout << "Insert permission(1 for worker, 2 for supervisor, 3 for admin): ";
    try{
      permission = DashBoard::askForOption(3);
      valid = true;
    }catch(ValueError &e){
      std::cout << "\nInvalid number, try again\n\n";
    }
  }
  newuser = new Employee(nif, password, permission);
  userDB->addUser(newuser);
}

void
DashBoard::onOffAlarm(Alarm *alarm){
  alarm->setOnOff(!alarm->getOnOff());
  std::cout << "Alarm turned " << (alarm->getOnOff()? "on.\n" : "off.\n") << std::endl;
}

void
DashBoard::showAlarmSts(Alarm *alarm, SensorDB *sensorDB){
  alarm->showInfo(sensorDB);
}

void
DashBoard::showAlarmMenu(Alarm alarm){
  bool valid = false;

  while(!valid){
    std::cout << "Manage Alarm." << std::endl;
    if(alarm.getOnOff()){
    std::cout << "1. Turn off Alarm." << std::endl;
    }else{
        std::cout << "1. Turn on Alarm." << std::endl;
    }
    std::cout << "2. Show status." << std::endl;
    std::cout << "3. Go back." << std::endl;
    std::cout << "Your option: ";
    try{
      this->option_ = DashBoard::askForOption(3);
      valid = true;
    }catch(ValueError &e){
      std::cout << "\nInvalid number, try again(1 - 2)\n\n";
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
}

void
DashBoard::delSensor(SensorDB *sensorDB){
  int id, i, maxid = 0;
  bool valid = false;

  std::cout << "Select sensor to delete(the id):\n";
  for(i = 0; i < (int)sensorDB->getSensors().size(); i++){
    if(maxid < sensorDB->getSensors()[i]->getId()){
      maxid = sensorDB->getSensors()[i]->getId();
    }
    std::cout << "Id: " << sensorDB->getSensors()[i]->getId() << " - ";
    switch(sensorDB->getSensors()[i]->getType()){
    case(TYPE_TEMP):
      std::cout << "Temperature.\n";
      break;
    case(TYPE_HUM):
      std::cout << "Humidity.\n";
      break;
    case(TYPE_MAG):
      std::cout << "Magnetic.\n";
      break;
    case(TYPE_LIGHT):
      std::cout << "Light.\n";
      break;
    case(TYPE_AIR):
      std::cout << "Air quality.\n";
      break;
    case(TYPE_TERMIC):
      std::cout << "Termic Camera.\n";
      break;
    case(TYPE_RGB):
      std::cout << "RGB Camera.\n";
      break;
    case(TYPE_CAM):
      std::cout << "Camera.\n";
      break;
    }
  }
  while(!valid){
    std::cout << "Your option: ";
    try{
      id = DashBoard::askForOption(maxid);
      if(sensorDB->getAsensor(id) == nullptr){
        throw ValueError();
      }
      valid = true;
    }catch(ValueError &e){
      std::cerr << "\nInvalid number, try again(1 - " << maxid << ")\n\n";
    }
  }
  sensorDB->delSensor(id);
  std::cout << "\nSensor deleted.\n" << std::endl;
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