#include <stdio.h>

int main(){
    int i = 3, j = 5;
    int *p = NULL, *q = NULL;
    p = &i;
    q = &j;


    q = &i; *q = 100;
    printf("%d\n", p);
    printf("%d\n", q);
    printf("%d\n", i);
    printf("%d\n", j);
    
}