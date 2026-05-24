#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"

TabelaHash* criaHash() {
    TabelaHash* tabela = (TabelaHash*) malloc(sizeof(TabelaHash));

    if (tabela != NULL)
        for (int i = 0; i < TAM_TABELA; i++){
            tabela->itens[i] = NULL;
        }

        tabela->tamanho = TAM_TABELA;
        tabela->totalUsuarios = 0;

    return tabela;
}

int valorString(char str[]){

    int soma = 0;

    for (int i = 0; str[i] != '\0'; i++){
        soma = soma + str[i];
    }

    return soma;
}

int chaveDivisao(int chave){
    return chave % TAM_TABELA;
}

int hashSenha(char senha[]){
    return valorString(senha);
}

int insereHash(TabelaHash* tabela, char username[], char senha[]) {

    if (tabela != NULL) {
        int indice = chaveDivisao(valorString(username));

        No* novo = (No*) malloc(sizeof(No));

        if (novo != NULL) {

            strcpy(novo->username, username);

            novo->hashSenha = hashSenha(senha);
            novo->prox = tabela->itens[indice];
            tabela->itens[indice] = novo;
            tabela->totalUsuarios++;

            return 1;
        }
    }

    return 0;
}

No* buscaHash(TabelaHash* tabela,char username[]) {

    if (tabela != NULL){

        int indice = chaveDivisao(valorString(username));

        No* aux = tabela->itens[indice];

        while (aux != NULL) {
            if (strcmp(aux->username, username) == 0) {
                return aux;
            }
            aux = aux->prox;
        }
    }
    return NULL;
}

int removeHash(TabelaHash* tabela, char username[]){}

void imprimeHash(TabelaHash* tabela){
    if (tabela != NULL) {

        printf("\nTABELA HASH\n");
        printf("Tamanho da tabela: %d\n", tabela->tamanho);
        printf("Quantidade de Usuários cadastrados: %d\n", tabela->totalUsuarios);

        for (int i = 0; i < TAM_TABELA; i++) {

            printf("\nPosição %d:\n", i);

            No* aux = tabela->itens[i];

            if (aux == NULL) {
                printf("Vazio\n");
            }

            while (aux != NULL) {

                printf("Usuário: %s\n", aux->username);
                printf("Hash da senha: %ld\n", aux->hashSenha);
                printf("\n|\n");
                printf("v\n\n");

                aux = aux->prox;
            }

            printf("NULL\n");
            printf("--------------------------------------------------\n");
        }
    }
}


void liberaHash(TabelaHash* tabela) {

    if (tabela != NULL) {
        for (int i = 0; i < TAM_TABELA; i++) {
            No* aux = tabela->itens[i];

            while (aux != NULL) {
                No* temp = aux;
                aux = aux->prox;

                free(temp);
            }
        }

        free(tabela);
    }
}