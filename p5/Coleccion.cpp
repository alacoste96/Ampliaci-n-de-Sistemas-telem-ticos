// Coleccion class member -and friend- function definitions.
#include <iostream>
#include <iomanip>
#include <stdexcept> 
#include "Coleccion.h" // Coleccion class definition

using namespace std;

ostream &operator<< (ostream &output, const Coleccion &array) {
  output << "[";
  for (size_t i = 0; i < array.getSize(); ++i)
    if (i != array.getSize() - 1){
      output << array.ptr [i] << ", "; // print each element
    }else{
      output << array.ptr [i]; // print last element
    }
  output << "]";
  return output;
}

istream &operator>> (istream &input, Coleccion &array) {
  int value;

  for(size_t i = 0; i < array.getSize(); ++i) {
    input >> value;
    array.ptr [i] = value; // store input in array
  }
  return input;
}

// default constructor for class Coleccion (default size 10)
// considering arraySize > 0, otherwise an exception should be thrown
Coleccion::Coleccion (int arraySize)
  : size (arraySize),
    ptr (new int [size]) {
  for (size_t i = 0; i < size; ++i)
    ptr [i] = 0; // set pointer-based array element
} // end Coleccion default constructor

// copy constructor for class Coleccion; must receive a reference to a Coleccion
Coleccion::Coleccion (const Coleccion &arrayToCopy)
  : size (arrayToCopy.size),
  ptr (new int [size]) {
    for (size_t i = 0; i < size; ++i)
      ptr [i] = arrayToCopy.ptr [i]; // copy into object
} // end Coleccion copy constructor

// destructor for class Coleccion
Coleccion::~Coleccion() {
  delete [] ptr; // release pointer-based array space
} // end destructor

size_t
Coleccion::getSize() const {
  return size; // return size
} // end function getSize

const Coleccion &
Coleccion::operator= (const Coleccion &right) {
  if (this!= &right) { // check for self-assignment
    delete [] ptr; // release pointer-based array space
    size = right.size; // copy size
    ptr = new int [size]; // allocate new pointer-based array space
    for (size_t i = 0; i < size; ++i)
      ptr [i] = right.ptr [i]; // copy into object
  } // end if
  return *this; // return object
} // end Coleccion assignment operator

bool
Coleccion::operator== (const Coleccion &right) const {
  if (this == &right) 
    return true; // same object (same reference)
  else if (size != right.size)
    return false; // different sizes
  else {
    for (size_t i = 0; i < size; ++i)
      if (ptr [i] != right.ptr [i])
        return false; // different elements
    return true; // same elements
  } // end else
} // end Coleccion equality operator

int &
Coleccion::operator[] (int index) {
  if (index < 0 || index >= static_cast<int>(size))
    throw out_of_range ("Index out of range"); // the classic exception for this problem
  return ptr [index]; // return modifiable lvalue
} // end Coleccion subscript operator

int
Coleccion::operator[] (int index) const {
  if (index < 0 || index >= static_cast<int>(size))
    throw out_of_range ("Index out of range"); // the classic exception for this problem
  return ptr [index]; // return rvalue
} // end Coleccion subscript operator


