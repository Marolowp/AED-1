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
        return 1;
    }
    return 0;
}

void inserirInicio(Head *lista, Dados dado){
        Nodo *novo =(Nodo*)malloc(sizeof(Nodo));
        if (novo == NULL){
            printf("Falha na memoria");
            return;
        }
        novo->info = dado;
        novo->prox = lista->pFirst;
        lista->pFirst = novo;
}

void inserirFinal(Head *lista, Dados dado){
    Nodo *novo = (Nodo *)malloc(sizeof(Nodo));
    if (novo == NULL){
        printf("Falha na memoria");
        exit(1);
    }

    novo->info = dado;
    novo->prox = NULL;
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

    free(lista);
}

int removerInicio(Head *lista){
    if (lista->pFirst == NULL) return 0; //lista vazia

    Nodo *remove = lista->pFirst;
    lista->pFirst = lista->pFirst->prox;

    free(remove);

    return 1; //executado com exito
}

int removerFinal(Head *lista){
    if (lista->pFirst == NULL) return 0; //Não foi possivel remover

    if (lista->pFirst->prox == NULL){
        free(lista->pFirst);
        lista->pFirst = NULL;
        return 1; //Foi possivel remover
    }

    Nodo *ant = lista->pFirst;
    Nodo *remove = ant->prox;

    while (remove->prox != NULL){
        ant = remove;
        remove = remove->prox; 
    }

    free(remove);
    ant->prox = NULL;

    return 1; 
}

int buscar(Head *lista, int cod, Dados *resultado){
    if(listaVazia(lista)) return 0;
    
    Nodo *atual = lista->pFirst;

    while (atual->info.cod != cod){
        atual = atual->prox;
        if (atual == NULL) return 0; //NAO ACHOU
    }

    *resultado = atual->info;

    return 1;
}