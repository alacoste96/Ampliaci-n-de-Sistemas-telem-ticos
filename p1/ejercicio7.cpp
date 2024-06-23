#include <iostream>

/*
----------------------------------------------------------------
                         Exercise 7
----------------------------------------------------------------
Write a program that takes as input a five-digit integer, separates 
that number into its individual digits, and prints them, each separated 
from the others by three spaces. For example, if the user enters the 
number 31250, the program should print: 3 1 2 5 0.
----------------------------------------------------------------
*/

enum{
    NUM_NUMS = 5,
};

int main(){
    int number, auxn, divisor = 10000, i;

    std::cout << "Introduce un numero de 5 digitos: ";
    std::cin >> number;

    std::cout << "Numeros separados por espacios: ";
    //.. Comments below explains the first iteration separating number 31250 into its digits
    for(i = 0; i < NUM_NUMS; i++){
        auxn = number / divisor; //.. get the left digit (auxn = 3)
        std::cout << auxn << " "; //.. print that digit
        auxn *= divisor; //.. 3 * 10000 = 30000
        number -= auxn; //.. 31250 - 30000 = 1250
        divisor /= 10;  //.. 10000 / 10 = 1000
    }
    std::cout << std::endl;
    return 0;
}