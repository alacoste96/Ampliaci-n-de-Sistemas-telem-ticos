#include <iostream>
#include <cmath>
/*
---------------------------------------------
                 Exercise 5
---------------------------------------------
Write a program that reads the radius of a circle 
as an integer and prints its diameter, circumference, 
and area. Use the constant value 3.14159 for π. 
Perform all calculations in output statements.
---------------------------------------------
*/

int main(){
    double pi = 3.14159;
    int radio;

    std::cout << "Introduzca el radio: ";
    std::cin >> radio;

    std::cout << "El diámetro del circulo es: " << 2 * radio << std::endl;
    std::cout << "El area del circulo es: " << pi * pow(radio, 2) << std::endl;
    std::cout << "La circunferencia del circulo es: " << 2 * pi * radio << std::endl;
    return 1;
}