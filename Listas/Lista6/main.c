
#include <stdio.h>
#include "fila.h"

int main() {
    Elem elem;
    Elem removido;

    // Cria a fila dinamicamente
    Fila *fila = criarFila();

    if (fila == NULL) {
        printf("Erro ao criar fila!\n");
        return 1;
    }

    printf("===== TESTE DA FILA =====\n\n");

    // 1. Testando enqueue()
    printf("--- Inserindo elementos ---\n");

    elem.valor = 10.5;
    enqueue(fila, elem);

    elem.valor = 20.75;
    enqueue(fila, elem);

    elem.valor = 30.25;
    enqueue(fila, elem);

    elem.valor = 40.8;
    enqueue(fila, elem);

    printf("Fila apos insercoes:\n");
    print(fila);

    // 2. Testando size()
    printf("\nQuantidade de elementos: %d\n", size(fila));

    // 3. Testando empty()
    printf("Fila vazia? %s\n", empty(fila) ? "Sim" : "Nao");

    // 4. Testando front()
    printf("\n--- Consultando o primeiro elemento ---\n");
    printf("Primeiro elemento: ");
    front(fila);

    printf("Quantidade apos front: %d\n", size(fila));

    // 5. Testando dequeue()
    printf("\n--- Removendo elementos ---\n");

    removido = dequeue(fila);
    printf("Elemento removido: %.2f\n", removido.valor);

    removido = dequeue(fila);
    printf("Elemento removido: %.2f\n", removido.valor);

    printf("\nFila apos remocoes:\n");
    print(fila);

    printf("Quantidade atual: %d\n", size(fila));

    // 6. Inserindo mais um elemento
    printf("\n--- Nova insercao ---\n");

    elem.valor = 50.9;
    enqueue(fila, elem);

    printf("Fila apos inserir 50.9:\n");
    print(fila);

    // 7. Testando clear()
    printf("\n--- Limpando a fila ---\n");

    clear(fila);

    printf("Quantidade apos clear: %d\n", size(fila));
    printf("Fila vazia? %s\n", empty(fila) ? "Sim" : "Nao");

    return 0;
}
