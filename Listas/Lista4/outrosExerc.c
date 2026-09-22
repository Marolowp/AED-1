#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int cod;
} Dados;

typedef struct Nodo {
    Dados info;
    struct Nodo *prox;
} Nodo;

typedef struct {
    Nodo *pFirst;
} Head;

Head *criaLista();
void inverterFuncao(Head *lista);
void imprimirLista(Head *lista);

int main(){
    Head *minhaLista = criaLista();
    
    Dados p1 = {100};
    Dados p2 = {102};
    Dados p4 = {103};
    Dados p5 = {104};
    Dados p6 = {105};
    
    imprimirLista(minhaLista);
    printf("\n--------------\n");
    inverterFuncao(minhaLista);
    imprimirLista(minhaLista);
    
}
Head *criaLista(){
    Head *p = (Head*)malloc(sizeof(Head));
    if (p == NULL){
        printf("Não alocou a mem");
        exit(1);
    }
    p->pFirst = NULL;
    return p;
}

void imprimirLista(Head *lista){
    Nodo *atual = lista->pFirst;
    int i = 0;
    while(atual != NULL){
        printf("Dado %d: %d\n", i, atual->info.cod);
        i++;
        atual = atual->prox;
    }
}

//Exercicio 5
void inverterFuncao(Head *lista){
    Nodo *atual = lista->pFirst;
    Nodo *prev = NULL;
    Nodo *next = NULL;
    
    while (atual != NULL){
        next = atual->prox;
        atual->prox = prev;
        prev = atual;
        atual = next;
    }
    lista->pFirst = prev;
}
