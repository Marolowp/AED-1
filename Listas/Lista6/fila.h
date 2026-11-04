#ifndef FILA_H
#define FILA_H

typedef struct elem {
    float valor;
    struct elem *prox;
} Elem;

typedef struct fila Fila;

typedef struct {
    int numero;
    char nome[100];
} Cliente;

typedef struct fila_cliente FilaCliente;

Fila *criarFila();
void reset(Fila *fila);
void reset(Fila *fila);
int empty(Fila *fila);
int size(Fila *fila);
void enqueue(Fila *fila, Elem elem);
Elem dequeue(Fila *fila);
void front(Fila *fila);
void clear(Fila *fila);
void print(Fila *fila);
void maior(Fila *fila);
void separarParesImpares(Fila *original, Fila *pares, Fila *impares);
void remover(Fila *fila, int valor);
void intercalar(Fila *fila1, Fila *fila2, Fila *resultado);
int gerarSenha(Fila *fila);
int chamarSenha(Fila *fila);
int consultarSenha(Fila *fila);


#endif