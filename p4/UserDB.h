#ifndef USERDB_H
#define USERDB_H

#include "Employee.h"

enum{
    MAX_EMPLOYEES = 100,
};

class UserDB {
private:
    Employee *employees_;
    int num_employees_;
public:
    UserDB();
    ~UserDB();
    void showAll();
    void showByPerm(int permision);
    void addUser(Employee *employee);
    void modUser(int id, Employee *employee);
};

#endif