#include <stdio.h>

//copy input to output ver 1

int main (){
    int c;

    c = getchar();
    while (c != EOF) {
        putchar(c);
        c = getchar();
    }
}