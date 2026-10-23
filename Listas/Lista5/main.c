#include <stdio.h>
#include "pilha.h"

int main() {
    Pilha pilha;

    // Inicializa a pilha
    reset(&pilha);

    // Testa push()
    Elem e = {'E'};
    Elem s = {'S'};
    Elem t = {'T'};
    Elem r = {'R'};
    Elem u = {'U'};
    Elem a = {'A'};
    Elem d = {'D'};
    Elem o = {'O'};
    Elem vazio = {' '};


    push(&pilha, e);
    push(&pilha, s);
    push(&pilha, t);
    push(&pilha, r);
    push(&pilha, u);
    push(&pilha, t);
    push(&pilha, u);
    push(&pilha, r);
    push(&pilha, a);
    push(&pilha, vazio);
    push(&pilha, d);
    push(&pilha, e);
    push(&pilha, vazio);
    push(&pilha, d);
    push(&pilha, a);
    push(&pilha, d);
    push(&pilha, o);
    push(&pilha, s);
    

    printf("A pilha possui %d elementos.\n", size(&pilha));
    top(&pilha);

    print(&pilha);

    printf("\n");

    printInvertido(&pilha);
    
    char palavra[10] = "radar";
    palindromo(palavra);
    // Testa pop()
    Elem removido;

    top(&pilha);
    removido = pop(&pilha);
    printf("Elemento removido: %c\n", removido.carac);

    printf("A pilha possui %d elementos.\n", size(&pilha));
    top(&pilha);

    removido = pop(&pilha);
    printf("Elemento removido: %c\n", removido.carac);

    printf("A pilha possui %d elementos.\n", size(&pilha));
    top(&pilha);

    removido = pop(&pilha);
    printf("Elemento removido: %c\n", removido.carac);

    printf("A pilha possui %d elementos.\n", size(&pilha));
    
    printf("Pilha vazia? %d\n", empty(&pilha));

    reset(&pilha);

    return 0;
} 

