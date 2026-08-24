#include <stdio.h>

void inverter(int *v, int n){
    int aux1;
    int aux2 = n;

    for (int i = 0; i < n; i++){
        if (aux2 == i && n % 2 == 0) break;
        if (aux2 == i+1 && n % 2 != 0) break;
        aux1 = v[i];
        v[i] = v[aux2 - 1];
        v[aux2 - 1] = aux1;
        aux2--;
    }
}

int main(){
    int v[5] = {10,20,30,40,50};    //vetor
    int n = 5;                      //tamanho

    inverter(v, n);

    for (int i = 0; i < n; i++){
        printf("%d ", v[i]);
    }

}