#include "Login.h"

Login::Login(int user, int passwd){
  this->user_ = user;
  this->passwd_ = passwd;
  std::cout << "Login" << std::endl;
  std::cout << "introduce your NIF without the final letter: " << std::endl;
  std::cin >> this->user_;
  std::cout << "introduce your password: " << std::endl;
  std::cin >> this->passwd_;
}

Employee *
Login::authenticate(UserDB *userDB){
  std::cout << "Authenticating..." << std::endl;
  for (const auto& employee: userDB->getEmployees()){
    if (employee->getNif() == this->user_ && employee->getId() == this->passwd_){
      std::cout << "You have been authenticated." << std::endl;
      return employee;
    }
  }
  std::cout << "NIF or password incorrect" << std::endl;
  return nullptr;
}

void
Login::setUser(int user){
  this->user_ = user;
}

void
Login::setPasswd(int passwd){
  this->passwd_ = passwd;
}

int
Login::getUser(){
  return this->user_;
}

int
Login::getPasswd(){
  return this->passwd_;
}
