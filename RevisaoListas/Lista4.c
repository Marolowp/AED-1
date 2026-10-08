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
void inserirFinal(Head *lista, Info dado);  //Insere dado no final
void imprimirLista(Head *lista); //Imprime lista
void removerInicio(Head *lista); //Remove inicio
void removerFinal(Head *lista); //Remove finall
void buscar(Head *lista, int valor); //Busca elemento;
void liberaLista(Head *lista); //Da free na lista inteira
void contElementos(Head *lista); //Conta quantos elementos tem na lista
void contElementosMaior(Head *lista, int valor); //Conta quantos elementos são maiores que o valor fornecido
void removeElementosIguais (Head *lista, int valor); //Remove elementos iguais da lista
void inverterLista(Head *lista);

int main(){
    printf("Exercicio 1:\n");
    Head *minhaLista = criaLista();
    printf("Testa lista vazia: \n");
    if(listaVazia(minhaLista)) printf("Lista vazia\n");
    else{
        printf("Lista contém elementos\n");
    }
    
    Info d1 = {10};
    Info d2 = {20};
    Info d3 = {30};
    Info d4 = {40};
    Info d5 = {50};
    Info d6 = {60};

    printf("Insere elementos......\n");
    inserirFinal(minhaLista, d4);
    inserirFinal(minhaLista, d5);
    inserirFinal(minhaLista, d6);
    inserirInicio(minhaLista, d3);
    inserirInicio(minhaLista, d2);
    inserirInicio(minhaLista, d1);
    printf("Elementos inseridos\n");

    if(listaVazia(minhaLista)) printf("Lista vazia\n");
    else{
        printf("Lista contém elementos\n");
    }

    imprimirLista(minhaLista);
    printf("\n");
    removerInicio(minhaLista);
    removerInicio(minhaLista);
    removerFinal(minhaLista);
    removerFinal(minhaLista);
    imprimirLista(minhaLista);

    inserirInicio(minhaLista, d2);
    inserirInicio(minhaLista, d1);

    printf("\n");
    imprimirLista(minhaLista);
    printf("\n");
    buscar(minhaLista, 70);
    contElementos(minhaLista);
    contElementosMaior(minhaLista, 20);

    inserirFinal(minhaLista, d6);
    inserirFinal(minhaLista, d6);
    inserirFinal(minhaLista, d6);
    inserirFinal(minhaLista, d6);

    printf("\n");
    imprimirLista(minhaLista);
    printf("\n");
    removeElementosIguais(minhaLista, 60);
    imprimirLista(minhaLista);

    liberaLista(minhaLista);
    printf("Lista liberada");

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
    Nodo *novo = (Nodo*)malloc(sizeof(Nodo));
    if (novo == NULL) return; //Erro de memoria

    novo->nodo= dado;               //atribui ao novo nodo o valor de dado
    novo->prox = lista->pFirst;     //faz com que o proximo elemento seja o primeiro elemento da lista antiga
    lista->pFirst = novo;           //atualiza o ponteiro do inicio para o novo dado
}

void inserirFinal(Head *lista, Info dado){
    Nodo *atual = lista->pFirst;
    
    
    Nodo *novo = (Nodo*)malloc(sizeof(Nodo));
    if (novo == NULL) return;

    novo->nodo = dado;
    novo->prox = NULL;
    if (lista->pFirst == NULL){
        lista->pFirst = novo;
        return;
    }

    while (atual->prox != NULL){
        atual = atual->prox;
    }
    
    atual->prox = novo;
}

void imprimirLista(Head *lista){
    Nodo *atual = lista->pFirst;
    
    if (atual == NULL) return;
    
    while (atual != NULL){
        printf("%d ", atual->nodo.valor);
        atual = atual->prox;
    }
}

void removerInicio(Head *lista){
    if (lista->pFirst == NULL) return;

    Nodo *removido = lista->pFirst;

    lista->pFirst = removido->prox;
    free(removido);
}

void removerFinal (Head *lista){
    if (lista->pFirst == NULL) return;

    Nodo *removido = lista->pFirst;
    Nodo *anterior = NULL;
    while(removido->prox != NULL){
        anterior = removido;
        removido = removido->prox;
    }
    free(removido);
    anterior->prox = NULL;   
}

void buscar(Head *lista, int valor){
    if (lista->pFirst == NULL) return;
    Nodo *atual = lista->pFirst;
    while (atual != NULL){
        if (atual->nodo.valor == valor){
            printf("Valor %d encontrado\n", valor);
            return;
        }
        atual = atual->prox;
    }
    printf("Valor %d não encontrado\n", valor);
}

void liberaLista(Head *lista){
    if (lista->pFirst == NULL){
        printf("Lista Vazia");
        return;
    }   
    while (lista->pFirst != NULL){
        Nodo *atual = lista->pFirst;
        lista->pFirst = lista->pFirst->prox; 
        free(atual);
    }
    free(lista);
}

void contElementos(Head *lista){
     int quantidade = 0;
     Nodo *atual = lista->pFirst;
     while (atual != NULL){
        quantidade++;
        atual = atual->prox;
    }
    printf("A lista tem %d elementos\n", quantidade);
}

void contElementosMaior(Head *lista, int valor){
    int quantidade = 0;
    Nodo *atual = lista->pFirst;
    while (atual != NULL){
        if (atual->nodo.valor > valor){
            quantidade++;
        }
        atual = atual->prox;
    }
    printf("Quantidade de elementos maiores que %d: %d\n", valor, quantidade);
}

void removeElementosIguais(Head *lista, int valor){
    Nodo *atual = lista->pFirst->prox;
    Nodo *anterior = lista->pFirst;

    while(atual != NULL){
        if (atual->nodo.valor == valor){
            Nodo *remover = atual;
            if (anterior == NULL){
                lista->pFirst = atual->prox;
            }
            else{
                anterior->prox = atual->prox;
            }
            atual = atual->prox;
            free(remover);
        }
        else {
            anterior = atual;
            atual = atual->prox;
        }
        
    }
}

void inverterLista(Head *lista){
    if (lista->pFirst == NULL || lista->pFirst->prox == NULL) return;
    Nodo *atual = lista->pFirst;
    Nodo *anterior = NULL;
    Nodo *proximo = NULL;

    while (atual != NULL){
        proximo = atual->prox;
        atual->prox = anterior;
        anterior = atual;
        atual = proximo;
    }
    lista->pFirst = anterior;
}