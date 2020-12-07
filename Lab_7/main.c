#include <stdio.h>
#include "allocation.h"
#include <sys/mman.h>


int main(int args, char* argv[]) {
    char *a;
    char *b;
    char *c;
    void * test;
    
    test = _malloc(CHUNK * 3);

    printf("%p", test);

    a = (char *) _malloc(sizeof(char) * 10000);
    for (int k = 0; k < 10000; ++k) {
        a[k] = k;
    }
    printf("Указатель на длинный массив %p \n", a);
    
    b = (char *) _malloc(sizeof(char) * 6);
    for (int i = 0; i < 6; ++i) {
        b[i] = 2;
    }
    printf("Указатель на шесть двоек %p \n", b);
    for (int j = 0; j < 6; ++j){
    printf("%i", b[j]);
    }
    printf("\n");

    c = (char *) _malloc(sizeof(char) * 1);
    c[0] = 'f';
    printf("Указатель на \"F\":  %p \n", c);
    printf("%c \n", *c);

    getchar();
	    
    _free(a);
    _free(c);
    _free(b);
    return 0;
}
