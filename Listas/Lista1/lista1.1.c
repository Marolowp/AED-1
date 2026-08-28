#include <stdio.h>

int main(){
    int i = 3, j = 5;
    int *p = NULL, *q = NULL;
    p = &i;
    q = &j;

    int resultA = *p;
    int resultB = *p - *q;
    int resultC = **&p;
    int resultD = 3 - *p / (*q) + 7;

    printf("%d\n", resultA);
    printf("%d\n", resultB);
    printf("%d\n", resultC);
    printf("%d\n", resultD);
}