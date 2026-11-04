#include "fila.h"
#include <stdio.h>
#include <stdlib.h>

struct fila {
    Elem *inicio;
    Elem *fim;
    int quantidade;
};

typedef struct nodoCliente {
    Cliente cliente;
    struct nodoCliente *prox;
} NodoCliente;

struct fila_cliente {
    NodoCliente *inicio;
    NodoCliente *fim;
    int quantidade;
};

Fila *criarFila() {
    Fila *fila = malloc(sizeof(Fila));

    if (fila == NULL) {
        return NULL;
    }

    reset(fila);

    return fila;
}

void reset(Fila *fila){
    fila->fim = NULL;
    fila->inicio = NULL;
    fila->quantidade = 0;
}

int empty(Fila *fila){
    if(fila->quantidade == 0){
        return 1;
    }
    return 0;
}

int size(Fila *fila){
    return fila->quantidade;
}

void front(Fila *fila){
    printf("O elemento da frente da fila é: %.2f\n", fila->inicio->valor);
}

void enqueue(Fila *fila, Elem elem) {
    Elem *novo = malloc(sizeof(Elem));

    if (novo == NULL) {
        return;
    }

    *novo = elem;
    novo->prox = NULL;

    if (empty(fila)) {
        fila->inicio = novo;
    } else {
        fila->fim->prox = novo;
    }

    fila->fim = novo;
    fila->quantidade++;
}

Elem dequeue(Fila *fila) {
    Elem *aux;
    Elem elem = {0};

    if (empty(fila)) {
        return elem;
    }

    aux = fila->inicio;
    elem = *aux;

    fila->inicio = aux->prox;

    if (fila->inicio == NULL) {
        fila->fim = NULL;
    }

    free(aux);

    fila->quantidade--;

    return elem;
}

void clear(Fila *fila){
    Elem *remove;
    
    if(empty(fila)){
        printf("fila já vazia\n");
    }

    while(!empty(fila)){
        *remove = dequeue(fila);
    }
}

void print(Fila *fila) {
    Elem *atual = fila->inicio;

    if (empty(fila)) {
        printf("Fila vazia!\n");
        return;
    }

    while (atual != NULL) {
        printf("%.2f ", atual->valor);
        atual = atual->prox;
    }

    printf("\n");
}

void maior(Fila *fila){
    Fila auxiliar;
    Elem elem;
    float maior;

    if (empty(fila)) {
        return 0;
    }

    reset(&auxiliar);

    elem = dequeue(fila);
    maior = elem.valor;
    enqueue(&auxiliar, elem);

    while (!empty(fila)) {
        elem = dequeue(fila);

        if (elem.valor > maior) {
            maior = elem.valor;
        }

        enqueue(&auxiliar, elem);
    }

    while (!empty(&auxiliar)) {
        elem = dequeue(&auxiliar);
        enqueue(fila, elem);
    }

    return maior;
}

void separarParesImpares(Fila *original, Fila *pares, Fila *impares) {
    Elem elem;
    Fila auxiliar;

    reset(&auxiliar);

    // Percorre a fila original
    while (!empty(original)) {
        elem = dequeue(original);

        // Verifica se é par ou ímpar
        if ((int)elem.valor % 2 == 0) {
            enqueue(pares, elem);
        } else {
            enqueue(impares, elem);
        }

        // Preserva o elemento para restaurar a original
        enqueue(&auxiliar, elem);
    }

    // Restaura a fila original
    while (!empty(&auxiliar)) {
        elem = dequeue(&auxiliar);
        enqueue(original, elem);
    }
}

void remover(Fila *fila, int valor) {
    Elem elem;
    int quantidade = size(fila);

    // Percorre a quantidade original de elementos
    for (int i = 0; i < quantidade; i++) {
        elem = dequeue(fila);

        // Reinsere somente os elementos diferentes
        if (elem.valor != valor) {
            enqueue(fila, elem);
        }
    }
}

void intercalar(Fila *fila1, Fila *fila2, Fila *resultado) {
    Elem elem;

    reset(resultado);

    while (!empty(fila1) || !empty(fila2)) {

        // Retira primeiro da fila 1
        if (!empty(fila1)) {
            elem = dequeue(fila1);
            enqueue(resultado, elem);
        }

        // Depois retira da fila 2
        if (!empty(fila2)) {
            elem = dequeue(fila2);
            enqueue(resultado, elem);
        }
    }
}

int gerarSenha(Fila *fila) {
    static int proximaSenha = 1;

    Elem elem;

    elem.valor = proximaSenha;

    enqueue(fila, elem);

    return proximaSenha++;
}

int chamarSenha(Fila *fila) {
    if (empty(fila)) {
        printf("Nao existem senhas aguardando!\n");
        return -1;
    }

    Elem elem = dequeue(fila);

    return (int)elem.valor;
}

int consultarSenha(Fila *fila) {
    if (empty(fila)) {
        return -1;
    }

    Elem elem = dequeue(fila);

    enqueue(fila, elem);

    return (int)elem.valor;
}