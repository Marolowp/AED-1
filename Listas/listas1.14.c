#include <stdio.h>
#include <stdlib.h>

int* montar_vetor(int *tam){
    int counter = 0;
    int valor = 0;
    int *v = NULL;

    if(*tam == 0){
        while (1){
            printf("Digite um valor do vetor 1: ");
            scanf("%d", &valor);
        
            if (valor == -1) break;

            int* temp = realloc(v, sizeof(int) * (counter + 1));
        
            if (temp == NULL){
                printf("Não foi possivel alocar memoria.");
                free(v);
                exit(1);
            }
        
            v = temp;
            v[counter] = valor;
            counter++;
        }
        
        printf("vetor 1 construido. \n");
        *tam = counter;
        
        return v;
    }
    else {
        int tam1 = *tam;
        for (int i = 0; i < tam1; i++){
            printf("Digite um valor: ");
            scanf("%d", &valor);

            int* temp = realloc(v, sizeof(int) * (i + 1));
            
            if (temp == NULL){
                printf("Não foi possivel alocar memoria.");
                free(v);
                exit(1);
            }

            v = temp;
            v[i] = valor;
        } 

        printf("Vetor 2 montado.");

        return v;
    }    
} 

int main(){
    int tam = 0;
    
    int* v1 = montar_vetor(&tam);
    int* v2 = montar_vetor(&tam);

    free(v1);
    free(v2);
}