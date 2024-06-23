#include <iostream>

/*
---------------------------------------------
                Exercise 6
---------------------------------------------
Write an application that displays a chessboard 
pattern as shown in section 'ejercicio 6' in here. 
First, do it using eight output statements (cout), 
and then attempt to do it using the fewest number 
of statements possible.
---------------------------------------------
*/

enum{
    ROWS = 8,
};

int main(){
    int i;
    char firstblack[] = "* * * * * * * *\n";
    char firstspace[] = " * * * * * * * *\n";

    std::cout << "Usando 8 instrucciones de cout:\n";
    std::cout << firstblack;
    std::cout << firstspace;
    std::cout << firstblack;
    std::cout << firstspace;
    std::cout << firstblack;
    std::cout << firstspace;
    std::cout << firstblack;
    std::cout << firstspace;

    std::cout << "Usando un bucle:\n";
    for(i = 0; i < ROWS; i++){
        if(i % 2 == 0){
            std::cout << firstblack;
        }else{
            std::cout << firstspace;
        }
    }
    return 0;
}