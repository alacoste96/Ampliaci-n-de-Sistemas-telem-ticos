#ifndef SUPERVISOR_H
#define SUPERVISOR_H

#include "Employee.h"

/**
 * \file Supervisor.h
 * \brief This file contains the declaration of the Supervisor class.
 */

/**
 * \class Supervisor
 * \brief Represents a Supervisor, which is a type of Employee.
 * 
 * This class represents a Supervisor, which is a type of Employee with intermediate permissions. He can manage alarms but cannot manage user's databases.
 */
class Supervisor: public Employee {
public:
    /**
     * \brief Constructor for the Supervisor class.
     * \param nif National Identification Number of the supervisor.
     * \param id Unique identifier of the supervisor.
     */
  Supervisor(int nif = 0, int id = 0):Employee(nif, id) {
      this->permission_ = 2; /**< Set permission level to 2 for supervisors. */
  };
};

#endif