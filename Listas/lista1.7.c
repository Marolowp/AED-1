#include <stdio.h>

void troca_vizinhos(int *a, int *b){
    int aux = *a;
    *a = *b;
    *b = aux;
}

int main(){
    int v[6] = {10,20,30,40,50,60};
    int *a = NULL;
    int *b = NULL;

    for (int i = 0; i < 6; i+=2){
        a = &v[i];
        b = &v[i + 1];
        troca_vizinhos(a,b);
    }

    for (int i = 0; i < 6; i++){
        printf("%d ", v[i]);
    }
}