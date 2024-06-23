#include <iostream>
/*
---------------------------------------------
                 Exercise 4     
---------------------------------------------
Write a program which ask the user 3 integers. 
The program has to print the addition, the mean, 
the product, the highest and the lowest number.
---------------------------------------------
*/

//.. Constants
enum{
    NUM_NUMS = 3, 
};

int sum(int *nums){
    int i, total = 0;

    for(i = 0; i < NUM_NUMS; i++)
        total += nums[i];
    return total;
}

int product(int *nums){
    int i, total = 1;

    for(i = 0; i < NUM_NUMS; i++)
        total *= nums[i];
    return total;
}

int lowest(int *nums){
    int i, lowest = nums[0];

    for(i = 1; i < NUM_NUMS; i++){
        if (nums[i] < lowest)
            lowest = nums[i];
    }
    return lowest;
}

int highest(int *nums){
    int i, highest = nums[0];

    for(i = 1; i < NUM_NUMS; i++){
        if (nums[i] > highest)
            highest = nums[i];
    }
    return highest;
}

int main(){
    int nums[NUM_NUMS], i;

    std::cout << "Introduzca 3 numeros enteros:\n";
    for (i = 0; i < NUM_NUMS; i++){
        std::cout << "Numero " << i + 1 << ": ";
        std::cin >> nums[i];
    }
    std::cout << "La suma es: " << sum(nums) << "\n";
    std::cout << "El promedio es: " << sum(nums)/NUM_NUMS << "\n";
    std::cout << "El producto es: " << product(nums) << "\n";
    std::cout << "El menor es: " << lowest(nums) << "\n";
    std::cout << "El mayor es: " << highest(nums) << "\n";
    return 0;
}