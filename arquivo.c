//
// Created by Vitor Aguiar Treglia on 07/09/25.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Pessoa.h"

#define SAIDA "../src/output.txt"
#define ARQUIVO "../src/NomeRG100M.txt"
#define TAM_LINHA 128

void novoNo(char nome[], long int rg, Pessoa** no, Pessoa* proximo, int* c, int* m);
void zeraLista(Pessoa** no, int* tamanhoLista, int* c, int* m);

void logOperacao(int c, int m, clock_t inicio);

void leArquivo(Pessoa** primeiro, Pessoa** ultimo, int* tamanhoLista) {
    clock_t inicio = clock();
    int c = 0;
    int m = 0;
    char linha[TAM_LINHA];
    char rg_temp[15];
    char nome_temp[30];

    zeraLista(primeiro, tamanhoLista, &c, &m);

    FILE *arquivo = fopen(ARQUIVO, "r");
    m++;
    if (arquivo == NULL) {
        perror("erro ao abrir o arquivo");
        exit(1);
    }
    c++;
    while (fgets(linha, sizeof(linha), arquivo)) {
        c+=2;
        if (sscanf(linha, "%29[^,],%14s", nome_temp, rg_temp) == 2) {
            if (*primeiro == NULL) {
                c++;
                novoNo(nome_temp, atol(rg_temp), primeiro, NULL, &c, &m);
                *ultimo = *primeiro;
                m++;
            } else {
                novoNo(nome_temp, atol(rg_temp), ultimo, NULL, &c, &m);
            }
            *tamanhoLista = *tamanhoLista + 1;
        }
    }
    fclose(arquivo);
    logOperacao(c, m, inicio);
}

void salvaArquivo(Pessoa* lista) {
    char linha[TAM_LINHA];
    int i;
    Pessoa* atual = lista;
    FILE *arquivo = fopen(SAIDA, "w");
    if (arquivo == NULL) {
        perror("erro ao abrir o arquivo");
        exit(1);
    }
    while (atual != NULL) {
        fprintf(arquivo, "%s,%ld\n", atual->nome, atual->rg);
        atual = atual->proximo;
    }
    fclose(arquivo);
    printf("arquivo salvo em %s", SAIDA);
    getchar();
}