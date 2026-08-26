#include <stdio.h>
#include <stdlib.h>

int* inserir (int* v, int* n, int valor){
    printf("digite um número para inserir no final do vetor. ");
    scanf("%d", &valor);
    int size = *n;

    int* temp = realloc(v, sizeof(int) * size);

    v = temp;
    v[size - 1] = valor;

    return v;
}

int* montar_vetor (int* n){
    int* v = NULL;
    int value = 0;
    int tamanho = 0;
    while (1){
        printf("Digite um número para colocar no vetor (-1 para terminar): ");
        scanf("%d", &value);

        if(value == -1) break;

        int* temp = realloc(v, sizeof(int) * tamanho);

        if(temp == NULL){
            printf("Erro ao alocar memoria.");
            free(v);
            exit(1);
        }

        v = temp;
        v[tamanho] = value;
        tamanho++;
    }

    printf("\nvetor montado\n");
    *n = tamanho;

    return v;
}

int main(){
    int n = 0;
    int* v = montar_vetor(&n);

    int valor = 0;

    int* vfinal = inserir(v, &n, valor);

    for (int i = 0; i < n; i++) printf("%d ", vfinal[i]);

    free(v);
}