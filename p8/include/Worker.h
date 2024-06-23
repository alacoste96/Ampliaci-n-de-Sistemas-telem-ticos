#ifndef WORKER_H
#define WORKER_H

/**
 * \file Worker.h
 * \brief This file contains the declaration of the Worker class.
 */

/**
 * \class Worker
 * \brief Represents a Worker, which is a type of Employee.
 * 
 * This class represents a Worker, which is a type of Employee with basic permissions. He can only manage sensors(except alarms).
 */
class Worker: public Employee {
public:
    /**
     * \brief Constructor for the Worker class.
     * \param nif National Identification Number of the worker.
     * \param id Unique identifier of the worker.
     */
  Worker(int nif = 0, int id = 0):Employee(nif, id) {
      this->permission_ = 1; /**< Set permission level to 1 for workers. */
  };
};

#endif