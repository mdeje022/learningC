#include <stdio.h>

//floating point version of the same assignment 

int main(){
    float fahr, celsius;

    int lower = 0;
    int upper = 300;
    int step = 20; 

    for(fahr = lower; fahr <= upper; fahr += step){
        celsius = (5.0 / 9.0) * (fahr - 32.0);
        printf("%3.0f\t%6.1f\n", fahr, celsius);
    }
}