#include <iostream>
#include <cmath>
/*
----------------------------------------------------
                    Exercise 9
----------------------------------------------------
Calculate the value of π from the infinite 
series: π = 4 − 4/3 + 4/5 − 4/7 + 4/9 − 4/11 + .... 
Print a table that shows the approximate value of π 
after each of the first 1000 terms of this series.
----------------------------------------------------
*/

enum{
    TERMS = 1000,
};

int main(){
    int i;
    double pi = 0.0;

    for(i = 0; i < TERMS; i++){
        pi += 4.0 / ((double)(i*2 + 1)*pow(-1.0, i));
        std::cout << "pi = " << pi << std::endl;
    }
    return 0;
}