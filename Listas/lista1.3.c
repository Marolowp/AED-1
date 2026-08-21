#include <stdio.h>

int main(){
    int v[5] = {0,1,2,3,4};
    int *p = NULL;

    p = v;
    printf("%d\n", p);
    p = v + 2;
    printf("%d\n", p);
    printf("%d", v[0]);
}