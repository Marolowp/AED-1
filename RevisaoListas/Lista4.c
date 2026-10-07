#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int valor;
} Info;

typedef struct Nodo{
    Info nodo;
    struct Nodo *prox;
} Nodo;

typedef struct{
    Nodo *pFirst;
} Head;
//Funcoes
Head *criaLista(); //cria lista
int listaVazia(Head *lista); //Verifica se a lista está vazia
void inserirInicio(Head *lista, Info dado); //Insere dado no início

int main(){
    Head *minhaLista = criaLista();
    if(listaVazia(minhaLista)) printf("Lista vazia");
    else{
        printf("Lista contém elementos");
    }
}

Head *criaLista(){
    Head *p = (Head*)malloc(sizeof(Head));
    if (p == NULL){
        exit(1); //Nao foi possivel alocar memoria
    }
    p->pFirst = NULL;
    return p;
}

int listaVazia(Head *lista){
    if(lista->pFirst == NULL) return 1; //Se vazia 1
    return 0; //se não 0
}

void inserirInicio(Head *lista, Info dado){
    if (lista->pFirst == NULL) return;

    Nodo *novo = (Nodo*)malloc(sizeof(Nodo));
    if (novo == NULL) return; //Erro de memoria

    novo->nodo.valor = dado.valor;  //atribui ao novo nodo o valor de dado
    novo->prox = lista->pFirst;     //faz com que o proximo elemento seja o primeiro elemento da lista antiga
    lista->pFirst = novo;           //atualiza o ponteiro do inicio para o novo dado
}

