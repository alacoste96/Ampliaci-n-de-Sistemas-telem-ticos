#ifndef DASHBOARD_H
#define DASHBOARD_H

#include "UserDB.h"
#include "SensorDB.h"
#include "Alarm.h"

#include <set>

class DashBoard {
private:
    Employee * user_;
    int option;
public:
    DashBoard(Employee *user = nullptr);
    void showMainMenu();
    void manageSensors();
};

#endif