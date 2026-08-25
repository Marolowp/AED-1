#include <stdio.h>
#include <stdlib.h>

int main(){
    int valores;
    int* v = NULL;
    int* addnumerros = NULL;
    int tamanhov = 0;

    while (valores != -1){
        printf("Digite um valor: ");
        scanf("%d", &valores);
        if (valores == -1) break;
        
        addnumerros = realloc(v, sizeof(int) * tamanhov);
        
        if (addnumerros != NULL){
            v = addnumerros;
            v[tamanhov] = valores;
        }
        else{
            free(addnumerros);
            printf("Erro no alloc");
        }
        tamanhov++;
    }

    for (int i = 0; i < tamanhov; i++){
        printf("%d ", v[i]);
    }
    free(addnumerros);
    free(v);
}