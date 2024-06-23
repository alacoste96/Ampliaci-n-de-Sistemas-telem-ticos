#include <iostream>
#include <cmath>

/*
---------------------------------------------------
                Exercise 8
---------------------------------------------------
Use while loops in each of the following cases:

a) Write an application that reads a non-negative 
    integer, calculates, and prints its factorial.
b) Write a program that estimates the value of the 
    mathematical constant e using the formula: 
    e = 1 + 1/1! + 1/2! + 1/3! + .... Ask the user 
    for the desired precision of e (i.e., the number 
    of terms in the sum).
c) Write an application that calculates the value 
    of e^x using the formula: 
    e^x = 1 + x/1! + x^2/2! + x^3/3! + ... 
    Ask the user for the desired precision of e 
    (i.e., the number of terms in the sum).
----------------------------------------------------
*/

int factorial(int n){
    int result = 1;

    if (n == 0)
        return result;
    do{
        result *= n;
        n--;
    }while(n > 0);
    return result;
}

double constE(int precision, double exponent){
    double result = 0.0;

    do{
        result += pow(exponent, precision)/ (double)factorial(precision);
        precision--;
    }while(precision >= 0);
    return result;
}

int main(){
    int n;
    double exp = 1.0;

    std::cout << "Introduzca el numero: ";
    std::cin >> n; //.. In this case, n is the number to do the factorial

    //.. section a) factorial
    std::cout << "Su factorial es: " << factorial(n) << std::endl;

    //.. section b) number 'e'
    std::cout << "Introduzca la precision para el numero 'e': ";
    std::cin >> n; //.. In this case, n is the precision
    std::cout << "El numero 'e' con " << n << " de precision es: " << constE(n, exp) << std::endl;

    //.. section c) number 'e^x'
    std::cout << "Introduzca la precision para el numero 'e': ";
    std::cin >> n; //.. In this case, n is the precision
    std::cout << "Introduzca el valor de su exponente: ";
    std::cin >> exp; //.. x is the exp of 'e'
    std::cout << "El numero 'e' con " << n << " de precision es ";
    std::cout << "y " << exp << " de exponente es: " << constE(n, exp) << std::endl;
    return 0;
}