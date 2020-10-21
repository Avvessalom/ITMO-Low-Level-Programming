#include <stdio.h>
#include "lab3_part2.h"


int main(int args, char *argv[]) {
    unsigned long n;
    printf("Please input your number: \n");
    scanf("%lu", &n);
    printf("(%lu) Is prime: ", n);
    puts(isPrime(n) ? "Yes" : "No");
    return 0;
}

int isPrime(unsigned long n){
    unsigned long counter;
    for (counter = 2; counter < n; counter++){
        if ((n % counter) == 0){
            return 0;
        }        
    }
    return 1;
}