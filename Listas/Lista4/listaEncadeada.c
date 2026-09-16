#include <stdio.h>
#include <stdlib.h>
#include "listaEncadeada.h"

Head *criaLista(Dados produto){
    Nodo *sentinela = malloc(sizeof(Dados));

    if (sentinela == NULL){
        printf("Não foi possível alocar memoria");
        exit(1);
    }
    sentinela->info = produto;
    sentinela->prox = NULL;

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