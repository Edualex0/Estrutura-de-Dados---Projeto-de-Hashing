#define TAM_TABELA  11 // a decidir
#define TAM_USERNAME 30
#define TAM_SENHA   30

typedef struct no {
    char username[TAM_USERNAME];
    long hashSenha;
    struct no* prox;
} No;

typedef struct tabelaHashing {
    No* buckets[TAM_TABELA];
    int tamanho;
    int totalUsuarios;
} TabelaHash;

TabelaHash* criaHash(int tamanho);
int insereHash(TabelaHash* tabela, char* username, char* senha);
No* buscaHash(TabelaHash* tabela, char* username);
int removeHash(TabelaHash* tabela, char* username);
void liberaHash(TabelaHash* tabela);
void imprimeHash(TabelaHash* tabela);