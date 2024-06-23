
#include <iostream>
#include "Admin.h"
#include "Employee.h"
#include "Supervisor.h"
#include "Worker.h"
#include "UserDB.h"
#include "Sensor.h"
#include "Temp.h"
#include "AirQuality.h"
#include "Humidity.h"
#include "LightQuality.h"
#include "Magnetic.h"
#include "Camera.h"

int main(){
    /*Employee *employptr;
    Admin admin = Admin(234, 2);
    Supervisor supervisor = Supervisor(345, 3);
    Worker worker = Worker(456, 4);
    UserDB userDB = UserDB();*/
    Temp temp = Temp();
    AirQuality airQuality = AirQuality();
    Humidity humidity = Humidity();
    LightQuality lightQuality = LightQuality();
    Magnetic magnetic = Magnetic();
    Camera camera = Camera(0, 0, std::make_tuple(4, 4));
    /*std::cout << "Employee: " << std::endl;
    empleado.showinfo();*/

    /*std::cout << "Admin: " << std::endl;
    admin.showinfo();

    std::cout << "Supervisor: " << std::endl;
    supervisor.showinfo();

    std::cout << "Worker: " << std::endl;
    worker.showinfo();*/

    /*std::cout << "UserDB: " << std::endl;
    employptr = &admin;
    userDB.addUser(employptr);

    employptr = &supervisor;
    userDB.addUser(employptr);

    employptr = &worker;
    userDB.addUser(employptr);

    userDB.showAll();
    userDB.showByPerm(3);
    userDB.modUser(2, &admin);
*/
    std::cout << "Temp: " << std::endl;
    temp.scan(20.0, 24.0);
    temp.showInfo();

    std::cout << "AirQuality: " << std::endl;
    airQuality.scan(20.0, 24.0);
    airQuality.showInfo();

    std::cout << "Humidity: " << std::endl;
    humidity.scan(20.0, 24.0);
    humidity.showInfo();

    std::cout << "LightQuality: " << std::endl;
    lightQuality.scan(20.0, 24.0);
    lightQuality.showInfo();

    std::cout << "Magnetic: " << std::endl;
    magnetic.scan(20.0, 24.0);
    magnetic.showInfo();


    return 0;
}