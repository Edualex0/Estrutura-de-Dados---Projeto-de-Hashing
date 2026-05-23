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

