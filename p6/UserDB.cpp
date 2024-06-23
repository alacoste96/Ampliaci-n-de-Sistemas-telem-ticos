#include "UserDB.h"

UserDB::UserDB() {
    this->num_employees_ = 0;
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
    for (const auto& employee: employees_){
        if (employee->getPermision() == permision){
            employee->showinfo();
        }
    }
}
