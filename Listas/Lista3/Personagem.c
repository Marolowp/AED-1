#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Personagem.h"

struct personagem {
    char *nome;
    int vida;
    int pataque;
};

Personagem *personagem_cria(char *nome){
    Personagem* personagem = (Personagem*)malloc(sizeof(Personagem));
    if (personagem == NULL) return NULL;

    personagem->nome = (char *)malloc(sizeof((strlen(nome) + 1) * sizeof(char))); //alloc dinamica de nome
    if (personagem->nome != NULL){
        strcpy(personagem->nome, nome);
    }

    personagem->vida = 100;
    personagem->pataque = 20;

    return personagem;
}

int personagem_vivo(Personagem *p){
    if (p->vida > 0) return 1;
    return 0;
}

void personagem_curar(Personagem *p){
    if(p == NULL) return;

    if(!personagem_vivo(p)){
        printf("Personagem está morto e não pode ser curado;");
        return;
    }

    p->vida += 25;
    if(p->vida > 100) p->vida = 100;
}

void personagem_status(Personagem *p){
    if (p == NULL) return;

    printf("------STATUS DO PERSONAGEM------\n");
    printf("Nome: %s\n", p->nome);
    printf("Vida: %d\n", p->vida);
    printf("Pontos de ataque: %d\n", p->pataque);
    printf("Estado: %s\n", personagem_vivo(p) ? "Vivo" : "Morto");
    printf("--------------------------------\n");
}

void personagem_libera(Personagem *p){
    free(p);
}

void personagem_atacar(Personagem* atacante, Personagem *alvo){
    
}