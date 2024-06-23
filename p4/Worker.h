#ifndef WORKER_H
#define WORKER_H

#include "Employee.h"

class Worker: public Employee{
public:
    Worker(int nif = 0, int id = 0):Employee(nif, id) {this->permision_ = 1;};
};

#endif