#include <stdio.h>
#include "hash.h"

int main() {

    char username[] = "danilo";
    char senha[] = "5468de";

    int valorUsername = valorString(username);
    int indice = chaveDivisao(valorUsername);
    int hashDaSenha = hashSenha(senha);

    printf("===== TESTE HASH =====\n");
    printf("Username: %s\n", username);
    printf("Valor da string: %d\n", valorUsername);
    printf("Indice da tabela: %d\n", indice);
    printf("Senha: %s\n", senha);
    printf("Hash da senha: %d\n", hashDaSenha);

    return 0;
}