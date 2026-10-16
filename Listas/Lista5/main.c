#include <stdio.h>
#include "pilha.h"

int main() {
    Pilha pilha;

    // Inicializa a pilha
    reset(&pilha);

    // Testa push()
    Elem a = {'A'};
    Elem b = {'B'};
    Elem c = {'C'};

    push(&pilha, a);
    push(&pilha, b);
    push(&pilha, c);



    // Testa pop()
    Elem removido;

    removido = pop(&pilha);
    printf("Elemento removido: %c\n", removido.carac);

    removido = pop(&pilha);
    printf("Elemento removido: %c\n", removido.carac);

    removido = pop(&pilha);
    printf("Elemento removido: %c\n", removido.carac);

    printf("Pilha vazia? %d\n", empty(&pilha));

    return 0;
} 

