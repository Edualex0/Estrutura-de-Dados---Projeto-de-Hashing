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
