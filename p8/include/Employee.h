#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <ctime>
#include <iostream>

/**
 * \file Employee.h
 * \brief This file contains the declaration of the Employee class.
 */

/**
 * \class Employee
 * \brief Represents an Employee.
 * 
 * This class represents an Employee with attributes such as NIF, ID, permission level, and timestamp.
 */
class Employee {
protected:
  int nif_; /**< National Identification Number of the employee. */
  int id_; /**< Unique identifier of the employee. Used as password in the login process. */
  int permission_; /**< Permission level of the employee (3 for admins, 2 for supervisors, 1 for workers). */
  std::time_t timestamp_; /**< Timestamp indicating when the employee was created. */

public:
    /**
     * \brief Constructor for the Employee class.
     * \param nif National Identification Number of the employee.
     * \param id Unique identifier of the employee.
     * \param permission Permission level of the employee.
     */
  Employee(int nif = 0, int id = 0, int permission = 0);

    /**
     * \brief Displays information about the employee.
     */
  void showinfo();
  std::time_t getTimestamp();
  int getNif() const;
  int getId() const;
  int getPermission() const;
  void setNif(int nif);
  void setId(int id);
  std::string getEmployType();
  void setPermission(int permission);
  void setTimestamp(std::time_t timestamp);

    /**
     * \brief Overloaded less-than operator to compare two employees.
     * \param right The employee to compare with.
     * \return True if this employee is less than the other employee, false otherwise.
     */
  bool operator<(const Employee &right) const;
};

#endif