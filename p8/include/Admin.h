#ifndef ADMIN_H
#define ADMIN_H
#include "Employee.h"
/**
 * \file Admin.h
 * \brief This file contains the declaration of the Admin class.
 */

/**
 * \class Admin
 * \brief Represents an Administrator, which is a type of Employee.
 * 
 * This class represents an Administrator, which is a type of Employee with elevated permissions. He can manage everything.
 */
class Admin: public Employee {
public:
    /**
     * \brief Constructor for the Admin class.
     * \param nif National Identification Number of the administrator.
     * \param id Unique identifier of the administrator.
     */
  Admin(int nif = 0, int id = 0):Employee(nif, id) {
    this->permission_ = 3; /**< Set permission level to 3 for administrators. */
  };
};

#endif