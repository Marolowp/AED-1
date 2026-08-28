#include <stdio.h>
#include <stdlib.h>

int* montar_vetor(int *n){
    int counter = 0;
    int valor = 0;
    int* v = NULL;

    while (1)
    {
        printf("Digite um número: ");
        scanf("%d", &valor);

        if (valor == -1) break;

        int* temp = realloc(v, sizeof(int) * counter);

        if (temp == NULL){
            printf("Erro ao alocar memoria. ");
            free(temp);
            exit(1);
        }

        v = temp;
        v[counter] = valor;
        counter++;
    }

    printf("\nvetor montado.\n");
    *n = counter;

    return v;
}

int* remover (int **v, int *n, int posicao){
    printf("Digite a posição do valor a ser removido: ");
    scanf("%d", &posicao);

    if (posicao < 0 || posicao >= (*n)) return 0;
    
    for (int i = posicao; i < *n - 1; i++){
        (*v)[i] = (*v)[i + 1];
    }

    (*n)--;

    if(*n == 0){
        free(*v);
        *v = NULL;
    }
    else {
        int *temp = (int *)realloc(*v, sizeof(int) * (*n));
        if (temp != NULL) *v = temp;
    }

    return *v;
}

int main(){
    int n = 0;
    int posicao = 0;
    int* v = montar_vetor(&n);

    int* vfinal = remover(&v, &n, posicao);

    for (int i = 0; i < n; i++){
        printf("%d ", vfinal[i]);
    }
    free(vfinal);
}