#include <stdio.h>
//count characters in input 1st Version

int main(){
    long nc = 0;

    while (getchar() != EOF){
        nc++;
    }

    printf("# of characters: %ld\n", nc);

}