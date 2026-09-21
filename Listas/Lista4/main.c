#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaEncadeada.h"

int main() {
    // 1. Criar a lista
    Head *minhaLista = criaLista();

    // 2. Verificar se está vazia
    if (listaVazia(minhaLista)) {
        printf(">> Lista criada com sucesso e no momento esta vazia.\n\n");
    }

    // Dados para inserção
    Dados p1 = {101, "Teclado", 150.00f};
    Dados p2 = {102, "Mouse", 80.50f};
    Dados p3 = {103, "Monitor", 950.00f};
    Dados p4 = {104, "Fone", 120.00f};
    Dados p5 = {105, "Headset", 110.00f};
    Dados p6 = {106, "Lamparina", 50.00f};
    Dados p7 = {107, "Carregado", 100.00f};
    Dados p8 = {108, "Placa V", 400.00f};
    
    // 3. Teste de inserção no início e no final
    printf("--- INSERINDO ELEMENTOS ---\n");
    inserirInicio(minhaLista, p2); // Lista: [102]
    inserirInicio(minhaLista, p1); // Lista: [101, 102]
    inserirFinal(minhaLista, p3);  // Lista: [101, 102, 103]
    inserirFinal(minhaLista, p4);  // Lista: [101, 102, 103, 104]

    // 4. Imprimir a lista completa
    printf("\n--- IMPRIMINDO LISTA ATUAL ---\n");
    imprimirLista(minhaLista);
    printf("\n");

    // 5. Teste de busca
    printf("--- BUSCANDO ELEMENTO ---\n");
    Dados resultado;
    int codigoBusca = 103;

    if (buscar(minhaLista, codigoBusca, &resultado)) {
        printf("Produto encontrado: Cod: %d | Nome: %s | Preco: R$ %.2f\n\n",
               resultado.cod, resultado.nome, resultado.preco);
    } else {
        printf("Produto com código %d nao foi encontrado.\n\n", codigoBusca);
    }

    // 6. Teste de remoção no início
    printf("--- REMOVENDO DO INICIO ---\n");
    if (removerInicio(minhaLista)) {
        printf("Elemento do inicio removido com sucesso.\n");
    }
    imprimirLista(minhaLista);
    printf("\n");

    // 7. Teste de remoção no final
    printf("--- REMOVENDO DO FINAL ---\n");
    if (removerFinal(minhaLista)) {
        printf("Elemento do final removido com sucesso.\n");
    }
    imprimirLista(minhaLista);
    printf("\n");

    // 8. Liberar a memória alocada
    
    //Exercio 2
    int quantidade = contar(minhaLista);
    printf("Quantidade de elementos na lista: %d\n", quantidade);
    //Exercicio 3
    inserirFinal(minhaLista, p5);
    inserirFinal(minhaLista, p6);

    int quantidadeMaior = quantMaior(p5.preco,minhaLista);
    printf("Quantidade de elementos mais caros que %.2f: %d\n",p5.preco, quantidadeMaior);

    //Exercicio 4
    removerCodigo(minhaLista, 103);
    imprimirLista(minhaLista);
    printf("\n--------------------------\n");

    //Exercicio 5
    inserirFinal(minhaLista, p7);
    inserirFinal(minhaLista, p8);
    inverterLista(minhaLista);
    imprimirLista(minhaLista);

    printf("\n--------------------------\n");
    //Exercicio 6
    inverterQuantFornecida(minhaLista, 3);
    imprimirLista(minhaLista);
    
    printf("--- LIBERANDO MEMORIA DA LISTA ---\n");
    liberaLista(minhaLista);
    printf("Memoria liberada com sucesso.\n");
    
    return 0;
}