#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define ARQUIVO "../src/NomeRG100M.txt"
#define TAM_LINHA 128

typedef struct Pessoa {
    long int rg;
    char nome[30];
    struct Pessoa* proximo;
} Pessoa;

Pessoa* alocaNo();
void leArquivo(Pessoa** primeiro, Pessoa** ultimo);
void imprimeLista(Pessoa* lista);

int main(void) {
    clock_t inicio = clock();
    Pessoa* primeiro = NULL;
    Pessoa* ultimo = NULL;
    leArquivo(&primeiro, &ultimo);
    imprimeLista(primeiro);
    clock_t fim = clock();
    printf("%ld", fim - inicio);
    return 0;
}

Pessoa* alocaNo() {
    Pessoa* no = (Pessoa*) malloc(sizeof(Pessoa));
    if (no == NULL) {
        perror("erro ao alocar memoria");
        return 0;
    }
    return no;
}

void leArquivo(Pessoa** primeiro, Pessoa** ultimo) {
    char linha[TAM_LINHA];
    int i = 0;
    Pessoa* novo;
    char rg_temp[15];
    FILE *arquivo = fopen(ARQUIVO, "r");
    if (arquivo == NULL) {
        perror("erro ao abrir o arquivo");
        exit(1);
    }

    while (fgets(linha, sizeof(linha), arquivo)) {
        novo = alocaNo();
        novo->proximo = NULL;
        if (sscanf(linha, "%30[^,],%15s", novo->nome, rg_temp) == 2) {
            novo->rg = atol(rg_temp);
        }
        if (*primeiro == NULL) {
            *primeiro = novo;
            *ultimo = novo;

        } else {
            (*ultimo)->proximo = novo;
            *ultimo = novo;
        }
    }
    fclose(arquivo);
}

void imprimeLista(Pessoa* lista) {
    Pessoa* atual = lista;
    while (atual != NULL) {
        printf("Nome: %s, RG: %ld\n", atual->nome, atual->rg);
        atual = atual->proximo;
    }
}