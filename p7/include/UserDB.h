#ifndef USERDB_H
#define USERDB_H

#include "Employee.h"
#include <set>

/**
 * \file UserDB.h
 * \brief This file contains the declaration of the UserDB class.
 */

/**
 * \struct EmployeeNifCompare
 * \brief For comparing Employees based on their NIF and ID.
 */
struct EmployeeNifCompare {
    /**
     * \brief Overloaded function call operator to compare two Employees.
     * \param left Pointer to the left Employee.
     * \param right Pointer to the right Employee.
     * \return True if the Nif and the Id of the left is diferent from the right one.
     */
    bool operator()(const Employee* left, const Employee* right) const {
        return (left->getNif() != right->getNif()) && (left->getId() != right->getId());
    }
};

/**
 * \class UserDB
 * \brief Represents a User's database.
 * 
 * This class is a container for the users. It is a set of employees and it is used to manage them.
 */
class UserDB {
private:
    std::set<Employee*, EmployeeNifCompare> employees_; /**< Set of employees stored in the database. */
    int num_employees_; /**< Number of employees in the database. */
public:
    /**
     * \brief Default constructor for the UserDB class.
     */
    UserDB();

    /**
     * \brief Displays information about all employees in the database.
     */
    void showAll();

    /**
     * \brief Displays information about employees with a specific permission level.
     * \param permission The permission level to filter employees by.
     */
    void showByPerm(int permission);

    /**
     * \brief Adds a new employee to the database.
     * \param employee Pointer to the Employee object to be added.
     */
    void addUser(Employee *employee);

    /**
     * \brief Modifies an existing employee in the database.
     * \param id The ID of the employee to be modified.
     * \param employee Pointer to the new Employee object with updated information.
     */
    void modUser(int id, Employee *employee);
    std::set<Employee*, EmployeeNifCompare> getEmployees() { return employees_; };
};

#endif
