#ifndef VALUEERROR_H
#define VALUEERROR_H

#include <stdexcept>

/**
 * \file ValueError.h
 * \brief This file contains the declaration of the ValueError class.
 */

/**
 * \class ValueError
 * \brief Represents a value error exception.
 * 
 * This class represents a custom exception for value errors, derived from std::runtime_error.
 */
class ValueError: public std::runtime_error {
public:
    /**
     * \brief Constructor for the ValueError class.
     */
  ValueError()
    : std::runtime_error("Value error") {}; /**< Initialize with a default error message. */
};

#endif
