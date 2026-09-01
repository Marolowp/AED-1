#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x;
    int y;
} Ponto;

Ponto *criar_ponto (int x, int y){
    Ponto *p = (Ponto*)malloc(sizeof(Ponto));
    if (p == NULL){
        printf("Erro ao alocar memoria.");
        free(p);
        exit(1);
    }

    p->x = NULL;
    p->y = NULL;
    return p;
}

void destruir_ponto(Ponto *p){
    free(p);
}

int main(){
    Ponto* p1 = criar_ponto(20,10);
    
    if (p1 != NULL){
        printf("Ponto criado: (%d, %d)", p1->x, p1->y);
        destruir_ponto(p1);
    }


}