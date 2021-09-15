#include <stdio.h>

//copy input to output ver 1

int main (){

    //characters are just numbers in the ascii table :P
    int c;

    c = getchar();
    while (c != EOF) {  //checks if we are giving end of file
        putchar(c); //this prints out the ascii equivalent of the int we gave it
        c = getchar();
    }
}