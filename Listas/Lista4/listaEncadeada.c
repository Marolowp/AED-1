#include <stdio.h>
#include <stdlib.h>
#include "listaEncadeada.h"

Head *criaLista(){
    Head *p = (Head*)malloc(sizeof(Head));
    if (p == NULL){
        exit(1);
    }
    p->pFirst = NULL;

    return p;

}

int listaVazia(Head *lista){
    if (lista->pFirst == NULL){
        return 0;
    }
    return 1;
}

void inserirInicio(Head *lista, Dados dado){
    Nodo *novo = malloc(sizeof(Dados));

    if (novo == NULL){
        exit(1);
    }

    novo->prox = lista->pFirst;
    lista->pFirst = novo;
}

void inserirFinal(Head *lista, Dados dado){
    Nodo *novo = malloc(sizeof(Dados));

    if (novo == NULL){
        exit(1);
    }

    if (lista->pFirst == NULL){
        lista->pFirst = novo;
        return;
    }

    Nodo *atual = lista->pFirst;
    
    while (atual->prox != NULL){
        atual = atual->prox;
    }
    
    atual->prox = novo;
}

void imprimirLista(Head *lista){
        Nodo *novo = lista->pFirst;

        while (novo != NULL){
            printf("Código: %d\n", novo->info.cod);
            printf("Nome do produto: %s\n", novo->info.nome);
            printf("Valor: %.2f\n\n", novo->info.preco);

            novo = novo -> prox;
        }
}

void liberaLista(Head *lista){
    if (lista->pFirst == NULL){
        printf("Lista Vazia");
        return;
    }
    Nodo *atual;
    while(lista->pFirst != NULL){
        atual = lista->pFirst;
        lista->pFirst = lista->pFirst->prox;   
        free(atual);
    }
}
