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

        printf("\nEscolha uma das opções: ");
        scanf("%d", &opcao);

        switch (opcao){

            case 1:
                printf("Digite o nome de usuário a ser cadastrado: ");
                scanf("%s", username);  
                printf("Digite a senha: ");
                scanf("%s", senha);
                
                if(insereHash(tabela, username, senha)){
                    printf("\nUsuário cadastrado com sucesso!\n");
                }   

                break;

            case 2:
                printf("\nLogin de usuário: ");
                scanf("%s", username);
                printf("Digite a senha: ");
                scanf("%s", senha);

                No* usuario = buscaHash(tabela, username);

                if(usuario != NULL && usuario->hashSenha == hashSenha(senha)){
                    printf("\nLogin bem-sucedido!\n");
                } else {
                    printf("Falha no login. Verifique o nome de usuário e a senha e tente novamente.\n");
                }

                break;
                         
            case 3:
                printf("\nUsuário a ser removido: ");
                scanf("%s", username);

                if (removeHash(tabela, username)) {
                    printf("\nUsuario removido!\n");
                } else {
                    printf("\nUsuario não encontrado!\n");
                }

                break;

            case 4:
                imprimeHash(tabela);

                break;

            case 0:
                printf("Encerrando...\n");

                break;
            
            }
        } while (opcao != 0);

    liberaHash(tabela);

    return 0;
} 
        
       
