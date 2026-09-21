#ifndef LISTAENCADEADA_H
#define LISTAENCADEADA_H

typedef struct {
    int cod;
    char nome[10];
    float preco;
} Dados;

typedef struct Nodo {
    Dados info;
    struct Nodo *prox;
} Nodo;

typedef struct {
    Nodo *pFirst;
} Head;

//Exercicio 1
Head *criaLista();
int listaVazia(Head *lista);
int removerInicio(Head *lista);
int removerFinal(Head *lista);
int buscar(Head *lista, int cod, Dados *resultado);
void inserirInicio(Head *lista, Dados dado);
void inserirFinal(Head *lista, Dados dado);
void imprimirLista(Head *lista);
void liberaLista(Head *lista);

//Exercicio 2
int contar(Head *lista);
//Exercicio 3
int quantMaior(float valor, Head *lista);
//Exercicio 4
void removerCodigo(Head *lista, int cod);
//Exercicio 5
void inverterLista(Head *lista);

#endif