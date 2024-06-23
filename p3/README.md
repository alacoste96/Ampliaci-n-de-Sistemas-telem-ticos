# P3-IdentClases_23-24

## Introduction

In this repository, you will find the [UML class diagram](https://github.com/clases-julio/p3-identclases-alacoste2017-1/blob/main/P2-uml.pdf) related to the final project *julio veganos e hijos*. This diagram will serve as the basis for structuring our code. We will explain it following the logic outlined below: First, we will explain the classes related to users/employees, then the classes related to sensors and the security system, and finally, the **dashboard** class that will bring everything together.

## Employee Class

Three subclasses (Administrator, Supervisor, and Regular Employee) will inherit from this class, sharing the same methods and attributes but with distinct values for each. The main idea is to have a distinction of permissions among different types of employees, allowing them to perform specific actions based on their roles.

1. **Administrator**: Has full access to all system functions.
2. **Supervisor**: Cannot perform read or write actions on the employee database, and therefore, cannot delete/modify employee data.
3. **Employee**: In addition to the Manager's restrictions:
    - Cannot add/modify sensors (requires a Manager's presence).
    - Cannot activate/modify alarms (handled by the Manager).
    - Can access sensor data.

## UserDB Class

As the name suggests, this is a database where all employees working in the greenhouse will be stored as a list. It provides methods to add, modify, delete, and query employees.

## Login Class

This class handles user authentication. When an employee attempts to log in, they will enter their ID as the username and a password, which is an integer from 1-1000. It uses the employee database for authentication. Once authenticated, it returns an object of the **Dashboard** class, with the employee attribute being the logged-in **employee**.

## Sensor Class

This class contains everything needed to deploy different objects of sensor types. The classes inheriting from this one will be humidity sensors, temperature sensors, etc. Each sensor will have an integer representing its sensor type, a unique identifier to distinguish it from sensors of the same type (for possible future modifications), and records of current values, values from the last day, and the last week.


## Alarm Class

This class contains the logic for the security system. This class will periodically collect values from magnetic sensors to ensure that everything is in place and there has been no intrusion. In the event of an intrusion, it will automatically call the police.

## SensorDB class

This class is a database where all sensors will be stored as a list. It provides methods to add, modify, delete, and query sensors

## Dashboard class

This class is the main class of the program. It contains all the logic for the program to run. It will be the class that the user will interact with. This class will use both databases (employee and sensor) to retrieve the necessary data for displaying to the user, as well as to have the capability to query the security system and take action. Of course, everything will depend on the permission level of the currently logged-in user in the system.


