#include <iostream>
/*
---------------------------------------------
                Exercise 1
---------------------------------------------
Program which ask the user for 2 ints and 
calculate their addition, product, difference
and division.
---------------------------------------------
*/
int getNumber(){
    int n;

    std::cout << "Enter a number: ";
    std::cin >> n;

    return n;
}

int main(){
    int n1, n2;

    n1 = getNumber();
    n2 = getNumber();

    std::cout << "The addition " << n1 << " + " << n2 << " = " << n1 + n2 << std::endl;
    std::cout << "The product " << n1 << " * " << n2 << " = " << n1 * n2 << std::endl;
    std::cout << "The difference " << n1 << " - " << n2 << " = " << n1 - n2 << std::endl;
    std::cout << "The division " << n1 << " : " << n2 << " = " << n1 / n2 << std::endl;
}