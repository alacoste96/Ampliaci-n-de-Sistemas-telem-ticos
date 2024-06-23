#include <iostream>
/*
----------------------------------------------------------------------
                        Exercise 2
----------------------------------------------------------------------
Program which prints integers from 1 to 4 separated by spaces. 
Do it following the next steps:

1. Using a simple instruction with the use of only 1 "<<" operator.
2. Using a simple instruction with the use of 4 "<<" operators.
3. using four instructions.
----------------------------------------------------------------------
*/
int main(){
    std::cout << "Section 1:\n";
    std::cout << "1 2 3 4\n";

    std::cout << "Section 2:\n";
    std::cout << "1 " << "2 " << "3 " << "4\n";

    std::cout << "Section 3:\n";
    std::cout << "1 ";
    std::cout << "2 ";
    std::cout << "3 ";
    std::cout << "4\n";
}