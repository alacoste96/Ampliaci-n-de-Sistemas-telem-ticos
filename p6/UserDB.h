#ifndef USERDB_H
#define USERDB_H

#include "Employee.h"
#include <set>

enum{
    MAX_EMPLOYEES = 100,
};

struct EmployeeNifCompare {
    bool operator()(const Employee* left, const Employee* right) const {
        return left->getNif() < right->getNif();
    }
};

class UserDB {
private:
    std::set<Employee*, EmployeeNifCompare> employees_;
    int num_employees_;
public:
    UserDB();
    void showAll();
    void showByPerm(int permision);
    void addUser(Employee *employee);
    void modUser(int id, Employee *employee);
    std::set<Employee*, EmployeeNifCompare> getEmployees(){return employees_;};
};

#endif