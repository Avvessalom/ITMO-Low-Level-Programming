#include <stdio.h>
#include <inttypes.h>
#include "lab3_part1.h"

const int firstArray[] = {1, 2, 3};
const int secondArray[] = {4, 5, 6};


int main(int args, char *argv[]){
    int64_t result;
    size_t firstSize = sizeof(firstArray) / sizeof(int);
    size_t secondSize = sizeof(secondArray) / sizeof(int);
    size_t minSize = firstSize < secondSize ? firstSize : secondSize;

    printf("Scalar product of given vectors: %d\n", scalarProduct(firstArray, secondArray, minSize));
    
}

int scalarProduct(const int* first, const int* second, size_t count){
    size_t i;
    int sum = 0;
    for (i = 0; i < count; i++){
        sum += (first[i] * second[i]);
    }   
    return sum;
}