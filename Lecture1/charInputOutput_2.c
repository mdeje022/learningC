#include <stdio.h>

int main(){
    int c;

    printf("test: %c", c = getchar()); //the fact that this is ok confuses me 

    while ((c = getchar()) != EOF){
        putchar(c);
    }
    return 0;

    
}