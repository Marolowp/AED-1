#include <stdio.h>
#include <stdlib.h>

int* concatenar (int* v1, int v1Size, int* v2, int v2Size, int *n3){
    *n3 = v1Size + v2Size;
    int* v3 = (int*)malloc(sizeof(int) * *n3);
    for (int i = 0; i < *n3; i++){
        if (i < v1Size) v3[i] = v1[i];
        if (i < v1Size + v2Size) v3[i] = v2[i];
    }
}

int* montar_vetor (int* tamanho){
    int *v = NULL;
    int count = 0;
    int input = 0;

    while (1) {
        printf("Digite um valor (-1 para sair): ");
        scanf("%d", &input); 

        if (input == -1) break;

        
        int *temp = realloc(v, sizeof(int) * (count + 1));
        if (temp == NULL) {
            printf("Erro ao alocar memoria.\n");
            free(v);
            exit(1);
        }
        
        v = temp;
        v[count] = input;
        count++;
    }

    printf("\nVetor 1 montado\n");
    *tamanho = count; 
    return v;
}



int main(){
    int tamanho1 = 0;
    int tamanho2 = 0;
    int* v1 = montar_vetor(&tamanho1);
    int* v2 = montar_vetor(&tamanho2);

    int tamanho3;

    int* v3 = concatenar(v1, tamanho1, v2, tamanho2, &tamanho3);
    for (int i = 0; i < tamanho3; i++){
        printf("%d", v3[i]);
    }
    
    /*int v2Size = count;
    int* v3Size = NULL; 

    int* v3 = concatenar(v1, &v1Size, v2, &v2Size, v3Size);

    for (int i = 0; i < v3Size; i++){
        printf("%d ", v3[i]);
    }
    */
}