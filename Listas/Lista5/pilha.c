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
    Elem caracter = remove->elem; 
  
    pilha->topo = remove->prox;  
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

int size(Pilha *pilha){
    return pilha->quantidade;
}

void clear(Pilha *pilha){
    while (!empty(pilha)){
        pop(pilha);
    }
}
void top(Pilha *pilha){
    if (empty(pilha)) return;
    printf("O elemento do topo é: %c\n", pilha->topo->elem.carac);
}

void print(Pilha *pilha){
    Pilha copia;
    Elem elem;

    reset(&copia);

    while(!empty(pilha)){
        elem = pop(pilha);
        push(&copia, elem);
    }

    while(!empty(&copia)){
        elem = pop(&copia);
        printf("%c", elem.carac);
        push(pilha, elem);
    }
}

void printInvertido(Pilha *pilha){
    Pilha copia;
    Elem elem;

    reset(&copia);

    while(!empty(pilha)){
        elem = pop(pilha);
        printf("%c", elem.carac);
        push(&copia, elem);
    }

    while(!empty(&copia)){
        elem = pop(&copia);
        push(pilha, elem);
    }
    printf("\n\n");
}

void palindromo(char *palavra){
    Pilha copia;
    Elem elem;
    
    reset(&copia);
    
    int i = 0;
    while(palavra[i] != '\0'){
        elem.carac = palavra[i];
        push(&copia, elem);
        i++;
    }

    i = 0;
    while(!empty(&copia)){
        elem = pop(&copia);
        if(palavra[i] != elem.carac){
            printf("Não é palindromo\n");
            break;
        }
        i++;
    }

    if(empty(&copia)){
       printf("É palindromo\n");
    }
}

void isBalanced(char *expressao){
    Pilha copia;
    Elem elem;

    reset(&copia);

    int i = 0;
    while(expressao[i] != '\0'){
        if(expressao[i] == '(' ||
           expressao[i] == '['||
           expressao[i] == '{'){
            elem.carac = expressao[i];
            push(&copia, elem);
        }
        if ((expressao[i] == ')' || expressao[i] == ']' || expressao[i] == '}') && empty(&copia)){
            printf("A expressão está nao corretamente balanceada.\n");
            return;
        }
        if((expressao[i] == ')' && copia.topo->elem.carac == '(' ) ||
            (expressao[i] == ']' && copia.topo->elem.carac == '[' ) ||
            (expressao[i] == '}' && copia.topo->elem.carac == '{' ) ){
            elem = pop(&copia);
        }
        i++;
    }
    if(empty(&copia)){
        printf("A expressão está corretamente balanceada.\n");
        return;
    }
    printf("A expressão está nao corretamente balanceada.\n");

}