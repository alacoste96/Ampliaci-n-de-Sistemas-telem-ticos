#ifndef ADMIN_H
#define ADMIN_H

#include "Employee.h"

class Admin: public Employee{
public:
    Admin(int nif = 0, int id = 0):Employee(nif, id) {this->permision_ = 3;};
};

#endif