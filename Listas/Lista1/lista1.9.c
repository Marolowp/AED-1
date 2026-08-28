#include <stdio.h>
#include <stdlib.h>

int* copia_vetor (int *v, int n){
    int* novov = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++){
        novov[i] = v[i];
    }
    return novov;
}

int main(){
    int v[5] = {1,2,3,4,5};
    int n = 5;

    int *result[n];
    
    for(int i = 0; i < n; i++){
        result[i] = copia_vetor(&v[i], n);
        printf("%d ", *result[i]);
    }
}