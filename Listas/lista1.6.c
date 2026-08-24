#include <stdio.h>

int soma(int *v, int n){
    int soma = 0;

    for (int i = 0; i < n; i++){
        int *p = &v[i];
        soma += *p;
    }
    return soma;
}

int main(){
    int v[5] = {1,2,3,4,5};
    int n = 5;

    int resultado = soma(v, n);

    printf("%d", resultado);
}