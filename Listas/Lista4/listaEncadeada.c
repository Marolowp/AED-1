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

//Exercio 2
int contar(Head *lista){
    int contador = 0;
    Nodo *atual = lista->pFirst;
    while (atual != NULL){
        contador++;
        atual = atual->prox;
    }
    return contador;
}

//Exercicio 3
int quantMaior(float valor, Head *lista){
    int contador = 0;
    Nodo *atual = lista->pFirst;
    while(atual != NULL){
        if (atual->info.preco > valor){
            contador++;
        }
        atual = atual->prox;
    }
    return contador;
}

//Exercicio 4
void removerCodigo(Head *lista, int cod){
    Nodo *atual = lista->pFirst->prox;
    Nodo *ant = lista->pFirst;
    while(atual != NULL){
        if (atual->info.cod == cod){
            Nodo *remover = atual;

            if (ant == NULL){
                lista->pFirst = atual->prox;
            } else {
                ant->prox = atual->prox;
            }

            atual = atual->prox;
            free(remover);
        } else {
            ant = atual;
            atual = atual->prox;
        }
    }
}

//Exercicio 5
void inverterLista(Head *lista){
    if (lista->pFirst == NULL || lista->pFirst->prox == NULL) return;
    Nodo *atual = lista->pFirst;
    Nodo *ant = NULL;
    Nodo *next = NULL;
    while (atual != NULL){
        next = atual->prox;
        atual->prox = ant;
        ant = atual;
        atual = next;
    }
    lista->pFirst = ant;
}
//Exercicio 6
void inverterQuantFornecida(Head *lista, int valor){
    if (lista->pFirst == NULL || lista->pFirst->prox == NULL) return;
    if(valor <= 1) return;
    int cont = valor;
    Nodo *antigoInicio = lista->pFirst;
    Nodo *atual = lista->pFirst;
    Nodo *ant = NULL;
    Nodo *next = NULL;
    while(atual != NULL){
        next = atual->prox;
        atual->prox = ant;
        ant = atual;
        atual = next;
        cont--;
        if (cont == 0) break;
    }
    antigoInicio->prox = next;
    lista->pFirst = ant;
}

void incorporaListas(Head *lista1, Head *lista2){
    if(lista1->pFirst == NULL || lista2->pFirst == NULL) return;
    Nodo *atual1 = lista1->pFirst;
    
    while (atual1->prox != NULL){
        atual1 = atual1->prox;
    }
    atual1->prox = lista2->pFirst;    
    lista2->pFirst = NULL;
}

void intercalaListas(Head *lista1, Head *lista2){
    if(lista1->pFirst == NULL || lista2->pFirst == NULL) return;
    Nodo *atual1 = lista1->pFirst;
    Nodo *atual2 = lista2->pFirst;
    Nodo *temp1 = NULL;
    Nodo *temp2 = NULL;
    while (1){
        if (atual2 != NULL && atual2 != NULL){
            temp1 = atual1->prox;
            temp2 = atual2->prox;
            atual1->prox = atual2;
            atual2->prox = temp1;
            atual1 = temp1;
            atual2 = temp2; 
        }
        else{
            break;
        }
    }
    lista1->pFirst = lista1->pFirst;
    lista2->pFirst = NULL;
}

//Exercicio 9
void separaParidade(Head *lista, Head *par, Head *impar){
    if (lista->pFirst == NULL) return;
    Nodo *atual = lista->pFirst;
    //Nodo *refPar = par->pFirst;
    //Nodo *refImpar = impar->pFirst; 

    int counter = 1;
    while(atual != NULL){
        if (counter % 2 == 0){
            inserirFinal(par, atual->info);
        }
        else if (counter % 2 != 0){
            inserirFinal(impar, atual->info);
        }
        atual = atual->prox;
        counter++;
    }
    

}
//Exercicio 10
void copiaLista(Head *lista1, Head *lista2){
    if(lista1->pFirst == NULL || lista2->pFirst != NULL) return;
    Nodo *atual1 = lista1->pFirst; 
    while (atual1 != NULL){
        inserirFinal(lista2, atual1->info);
        atual1 = atual1->prox;
    }
}