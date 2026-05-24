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

        switch (opcao){

            case 1:
                printf("Digite o nome de usuário: ");
                scanf("%s", username);  
                printf("Digite a senha: ");
                scanf("%s", senha);
                
                if(insereHash(tabela, username, senha)){
                    printf("Usuário cadastrado com sucesso!\n");
                }   

                break;

            }
       
        } while (opcao != 0);

    liberaHash(tabela);

    return 0;
} 
        
       
