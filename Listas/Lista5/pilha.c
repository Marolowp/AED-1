#include "pilha.h"
#include <stdio.h>
#include <stdlib.h>

void reset (Pilha *pilha){
    pilha->topo = NULL;
    pilha->quantidade = 0;
}
void push(Pilha *pilha, Elem elem){
    Nodo *novo = (Nodo*)malloc(sizeof(Nodo));

    if (novo == NULL){
        return; 
    }

    novo->elem = elem;
    novo->prox = pilha->topo;
    pilha->topo = novo;

    pilha->quantidade++;
}

Elem pop(Pilha *pilha){
    Nodo *remove;
    if(empty(pilha)){
        printf("pilha vazia\n");
        return (Elem){'\0'};
    }
    
    remove = pilha->topo;
    pilha->topo = remove->prox;
    
    Elem caracter = remove->elem; 
    free(remove);

    pilha->quantidade--;
    return caracter;
}

int empty(Pilha *pilha){
    if (pilha->quantidade == 0){
        return 1;
    }
    return 0;
}