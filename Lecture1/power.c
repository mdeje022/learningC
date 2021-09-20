#include <stdio.h>
__uint32_t power(int base, int n);

int main(){
    int i;

    for (i = 0; i < 10; i++){
        printf("%d %d %d\n", i, power(2,i), power(-3, i));
    }

    return 0;
}

__uint32_t power(int base, int n){
    int p; 

    for (p = 1; n > 0; n--){
        p = p * base;
    }
    return p;
}