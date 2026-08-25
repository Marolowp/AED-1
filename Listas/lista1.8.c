#include <stdio.h>

void min_max(int *v, int n, int *pmax, int *pmin){
    *pmax = v[0];
    *pmin = v[0];

    for (int i = 0; i < n; i++){
        int aux = v[i];
        if (aux > *pmax){
            *pmax = v[i];
        }
        if (aux < *pmin){
            *pmin = v[i];
        }
    }
}

int main(){
    int v[6] = {0,1,2,3,4,5};
    int n = 6;
    int pmax;
    int pmin;

    min_max(v, n, &pmax, &pmin);
    
    printf("%d %d", pmax, pmin);
}