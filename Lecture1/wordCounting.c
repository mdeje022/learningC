#include <stdio.h>
#define IN 0
#define OUT 1

int main(){
    int c =0;
    int wordCount = 0;
    int state = OUT;
    while ((c = getchar()) != EOF){
        if (c == '\n' || c == ' ' || c == '\t'){
            state = OUT;
        } else if (state == OUT){
            state = IN;
            ++wordCount;
        }
    }
    printf("Word count: %d\n", wordCount);
    return 0;
}