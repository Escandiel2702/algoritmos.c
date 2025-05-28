/*        Trabalho de algoritmos:
Nome:Nicolas Santos Escandiel.
professor: Alessandro João Brassanini.
Nota:
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PRODUTOS 200
#define MAX_CLIENTES 50
#define PRECO_MIN 5
#define PRECO_MAX 100

int main() {
    int numProdutos, numClientes;
    float produtos[MAX_PRODUTOS];
    int clienteProduto[MAX_CLIENTES];
    float totalVendas = 0;

    srand(time(NULL)); // Inicializa o gerador de números aleatórios

    // Gerar número aleatório de produtos e clientes
    numProdutos = rand() % MAX_PRODUTOS + 1;   // 1 a 200
    numClientes = rand() % MAX_CLIENTES + 1;   // 1 a 50

    // Preços aleatórios para os produtos
    for (int i = 0; i < numProdutos; i++) {
        produtos[i] = PRECO_MIN + (rand() % (PRECO_MAX - PRECO_MIN + 1));
    }

    printf("Simulacao para:\n");
    printf("  %d produtos\n", numProdutos);
    printf("  %d clientes\n", numClientes);
    printf("----------------------------------------\n");
    printf("Cliente    Produto    Valor (R$)\n");
    printf("----------------------------------------\n");

    for (int i = 0; i < numClientes; i++) {
        int produtoEscolhido = rand() % numProdutos;
        clienteProduto[i] = produtoEscolhido;
        float valor = produtos[produtoEscolhido];
        totalVendas += valor;

        printf("%3d        %3d        %6.2f\n", i, produtoEscolhido, valor);
    }

    printf("\nTOTAL DE VENDAS      %.2f\n", totalVendas);
    printf("Pressione qualquer tecla para continuar...\n");

    getchar(); // Espera uma tecla para encerrar (em sistemas Windows)
    return 0;
}

