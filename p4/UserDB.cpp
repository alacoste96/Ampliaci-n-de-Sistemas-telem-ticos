#include "UserDB.h"

UserDB::UserDB() {
    this->num_employees_ = 0;
}

UserDB::~UserDB(){
    delete[] employees_;
}

void
UserDB::addUser(Employee *employee){
    std::cout << "Adding user..." << std::endl;
    
    Employee *aux = new Employee[num_employees_ + 1];

    std::copy(employees_, employees_ + num_employees_, aux);

    aux[num_employees_] = *employee;

    delete[] employees_;

    employees_ = aux;

    num_employees_++;
}


void
UserDB::showAll(){
    std::cout << "Showing all users..." << std::endl;
    for (int i = 0; i < this->num_employees_; i++){
        this->employees_[i].showinfo();
    }
}

void
UserDB::modUser(int id, Employee *employee){
    std::cout << "Modifying user..." << std::endl;
    /*for (int i = 0; i < this->num_employees; i++){
        if (this->employees[i].getId() == id){
            this->employees[i] = employee;
        }
    }*/
}

void
UserDB::showByPerm(int permision){
    std::cout << "Showing users by permision..." << std::endl;
    for (int i = 0; i < this->num_employees_; i++){
        if (this->employees_[i].getPermision() == permision){
            this->employees_[i].showinfo();
        }
    }
}