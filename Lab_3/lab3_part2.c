#include <stdio.h>

int isPrime(unsigned long n);
int main() {
    unsigned long n;
    printf("Please input your number: \n");
    scanf("%lu", &n);
    printf("(%lu) Is prime: ", n);
    printf(isPrime(n) ? "Yes\n" : "No\n");
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