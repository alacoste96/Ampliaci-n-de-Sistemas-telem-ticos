#ifndef SUPERVISOR_H
#define SUPERVISOR_H

#include "Employee.h"

class Supervisor: public Employee{
public:
    Supervisor(int nif = 0, int id = 0):Employee(nif, id) {this->permision_ = 2;};
};

#endif