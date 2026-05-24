#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"

int main() {

    TabelaHash* tabela = criaHash();
    
    int opcao;
    char username[TAM_USERNAME];
    char senha[TAM_SENHA];

     do {

        printf("\nSISTEMA DE CADASTRO\n");
        printf("1 - Cadastrar usuario\n");
        printf("2 - Login\n");
        printf("3 - Remover usuario\n");
        printf("4 - Imprimir tabela\n");
        printf("0 - Sair\n");
 
        printf("Escolha uma das opções: ");
        scanf("%d", &opcao);

        // usar switch case para as funções anteriores
     } while (opcao != 0);

     liberaHash(tabela);

    return 0;
}