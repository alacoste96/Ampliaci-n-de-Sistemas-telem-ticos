#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <ctime>
#include <iostream>

class Employee {
protected:
    int nif_;
    int id_;
    int permision_;
    std::time_t timestamp_;

public:
    Employee(int nif = 0, int id = 0, int permision = 0);
    void showinfo();
    std::time_t getTimestamp();
    int getNif();
    int getId();
    int getPermision();
    void setNif(int nif);
    void setId(int id);
    void setPermision(int permision);
    void setTimestamp(std::time_t timestamp);

};

#endif