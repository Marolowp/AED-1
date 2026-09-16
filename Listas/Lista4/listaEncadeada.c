#include <stdio.h>
#include <stdlib.h>
#include "listaEncadeada.h"

Head *criaLista(){
    Head *p = (Head*)malloc(sizeof(Head));
    if (p == NULL){
        free(p);
        exit(1);
    }
    p->pFirst = NULL;

    return p;

}

int listaVazia(Head *lista){
    if (lista == NULL){
        printf("Lista vazia.");
        return 1;
    }
    return 0;
}

void inserirInicio(Head *lista, Dados dado){
    Nodo *novo = criaLista(dado);

    novo->prox = lista->pFirst;
    lista->pFirst = novo;
}