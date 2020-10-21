#include <criterion/criterion.h>
#include "lab3_part2.h"

Test(one, test){
    cr_assert((isPrime(1), "Yes"));
}

Test(two, test){
    cr_assert((isPrime(2), "Yes"));
}

Test(three, test){
    cr_assert((isPrime(3), "Yes"));
}

Test(Four, test){
    cr_assert((isPrime(4), "No"));
}

Test(five, test){
    cr_assert((isPrime(5), "Yes"));
}

Test(six, test){
    cr_assert((isPrime(6), "No"));
}

Test(seven, test){
    cr_assert((isPrime(7), "Yes"));
}
Test(eight, test){
    cr_assert((isPrime(8), "No"));
}

Test(nine, test){
    cr_assert((isPrime(9), "No"));
}

Test(ten, test){
    cr_assert((isPrime(10), "No"));
}

Test(eleven, test){
    cr_assert((isPrime(11), "Yes"));
}

Test(twelve, test){
    cr_assert((isPrime(12), "No"));
}

Test(thirteen, test){
    cr_assert((isPrime(13), "Yes"));
}

Test(seventeen, test){
    cr_assert((isPrime(17), "Yes"));
}

Test(nineteen, test){
    cr_assert((isPrime(19), "Yes"));
}

Test(twenty_three, test){
    cr_assert((isPrime(23), "Yes"));
}

Test(twenty_nine, test){
    cr_assert((isPrime(29), "Yes"));
}

Test(thirty_one, test){
    cr_assert((isPrime(31), "Yes"));
}

Test(thirty_seven, test){
    cr_assert((isPrime(37), "Yes"));
}

Test(forty_one, test){
    cr_assert((isPrime(41), "Yes"));
}

Test(forty_four, test){
    cr_assert((isPrime(43), "Yes"));
}

Test(forty_seven, test){
    cr_assert((isPrime(47), "Yes"));
}

Test(fifty_three, test){
    cr_assert((isPrime(53), "Yes"));
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