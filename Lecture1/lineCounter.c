#include <stdio.h>

int main(){
    int c, nl;
    nl = 0;

    while ((c = getchar()) != EOF){
        if (c == '\n'){
            ++nl; //in this case the location of the ++ doesn't matter :P
        }
    }
    printf("%d\n", nl);

}