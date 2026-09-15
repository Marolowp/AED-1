#include <stdio.h>
#include "Personagem.h"

int main(){
    Personagem *heroi = personagem_cria("Geralt");
    Personagem *monstro = personagem_cria("Goblin");

    personagem_status(heroi);
    personagem_status(monstro);

    printf("\n--- Combate ---\n");
    personagem_atacar(heroi, monstro);
    personagem_atacar(monstro, heroi);

    personagem_status(heroi);
    personagem_status(monstro);

    printf("\n--- Cura ---\n");
    personagem_curar(heroi);

    printf("\n--- Ataques Finais ---\n");
    personagem_atacar(heroi, monstro);
    personagem_atacar(heroi, monstro);
    personagem_atacar(heroi, monstro);
    personagem_atacar(heroi, monstro);

    personagem_status(monstro);

    // Tentativa de ataque apos derrota
    personagem_atacar(heroi, monstro);

    // Liberando a memoria alocada
    personagem_libera(heroi);
    personagem_libera(monstro);

    return 0;
}