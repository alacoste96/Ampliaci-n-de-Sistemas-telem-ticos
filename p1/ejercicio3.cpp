#include <iostream>
/*
----------------------------------------------------------------
                        Exercise 3
----------------------------------------------------------------
Write a program which ask the user to write 2 integers. 
The program has to write the highest one followed by 
the expresion "es más grande". If both numbers are equal, 
the program has to print the message "estos números son iguales"
----------------------------------------------------------------
*/
int main(){
    int n1, n2;

    std::cout << "Escriba el primer numero: ";
    std::cin >> n1;

    std::cout << "Escriba el segundo numero: ";
    std::cin >> n2;

    if (n1 > n2) {
        std::cout << n1 << " es mas grande\n";
    }else if (n1 == n2){
        std::cout << "Estos numeros son iguales\n";
    }else{
        std::cout << n2 << " es mas grande\n";
    }
}