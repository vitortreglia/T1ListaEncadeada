//
// Created by Vitor Aguiar Treglia on 07/09/25.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "Pessoa.h"

void logOperacao(int c, int m, clock_t inicio);

Pessoa* alocaNo() {
    Pessoa* no = (Pessoa*) malloc(sizeof(Pessoa));
    if (no == NULL) {
        perror("erro ao alocar memoria");
        return 0;
    }
    no->proximo = NULL;
    return no;
}

void zeraNo(Pessoa** no) {
    free(*no);
}

void zeraLista(Pessoa** no, int* tamanhoLista, int* c, int* m) {
    Pessoa* novo;
    while (*no != NULL) {
        (*c)++;
            novo = (*no)->proximo;
            (*m)++;
            zeraNo(no);
            (*m)++;
            *no = novo;
            (*m)++;

    }
    *tamanhoLista = 0;
}

void novoNo(char nome[], long int rg, Pessoa** no, Pessoa* proximo, int* c, int* m) {
    Pessoa* novo = alocaNo();
    *m = *m + 3;
    (*c)++;
    strcpy(novo->nome, nome);
    (*m)++;
    novo->rg = rg;
    (*m)++;
    novo->proximo = proximo;
    (*m)++;
    if (*no != NULL && *no != proximo) {
        (*no)->proximo = novo;
        (*m)++;
    }
    (*c)++;
    *no = novo;
    (*m)++;
}

void novoElemento(Pessoa** primeiro, Pessoa** ultimo, int* tamanhoLista, int pos) {
    clock_t inicio = clock();
    int c = 0;
    int m = 0;
    char nome[30];
    long int rg;

    printf("Digite o nome\n");
    scanf("%s", nome);
    printf("Digite o RG\n");
    scanf("%ld", &rg);
    getchar();

    if (pos == 0) {
        c++;
        novoNo(nome, rg, primeiro, *primeiro, &c, &m);
        (*tamanhoLista)++;
        logOperacao(c, m, inicio);
    } else if (pos == *tamanhoLista) {
        c+=2;
        novoNo(nome, rg, ultimo, NULL, &c, &m);
        (*tamanhoLista)++;
        logOperacao(c, m, inicio);
    } else if (pos < *tamanhoLista) {
        c+=3;
        Pessoa* atual = *primeiro;
        m++;
        for (int i = 1; i < pos; i++) {
            c++;
            atual = atual->proximo;
            m++;
        }
        novoNo(nome, rg, &atual, atual->proximo, &c, &m);
        (*tamanhoLista)++;
        logOperacao(c, m, inicio);
    } else {
        printf("Erro ao inserir elemento\n");
    }
}

void apagaNo(Pessoa* anterior, Pessoa** no, int* c, int* m) {
    Pessoa* temp = (*no)->proximo;
    if (anterior == *no) {
        zeraNo(no);
        *no = temp;
        *m = *m + 3;
    } else {
        zeraNo(no);
        if (temp == NULL)
            anterior->proximo = NULL;
        else
            *anterior->proximo = *temp;
        *m = *m + 2;
    }
    (*c)++;
}

void removeElemento(Pessoa** primeiro, Pessoa** ultimo, int* tamanhoLista, int pos) {
    clock_t inicio = clock();
    int c = 0;
    int m = 0;

    if (pos == 0) {
        c++;
        apagaNo(*primeiro, primeiro, &c, &m);
        (*tamanhoLista)--;
        logOperacao(c, m, inicio);
    } else if (pos < *tamanhoLista) {
        c+=3;
        Pessoa* atual = *primeiro;
        m++;
        for (int i = 1; i < pos; i++) {
            c++;
            atual = atual->proximo;
            m++;
        }
        apagaNo(atual, &atual->proximo, &c, &m);
        if (pos == *tamanhoLista-1) {
            *ultimo = atual;
            (*ultimo)->proximo = NULL;
        }
        (*tamanhoLista)--;
        logOperacao(c, m, inicio);
    } else {
        printf("Erro ao remover elemento\n");
    }
}

void procurarElemento(Pessoa* primeiro) {
    long int rgBusca;
    int sucesso = 0;
    int c = 0;
    int m = 0;
    int i = 0;
    Pessoa* atual = primeiro;
    m++;
    printf("Digite o RG do elemento a ser procurado\n");
    scanf("%ld", &rgBusca);
    getchar();
    clock_t inicio = clock();

    while (atual != NULL && sucesso == 0) {
        c+=3;
        if (atual->rg == rgBusca) {
            printf("Elemento encontrado na posicao %d\nNome: %s RG: %ld\n", i, atual->nome, atual->rg);
            sucesso = 1;
        } else {
            atual = atual->proximo;
            i++;
        }
    }
    if (sucesso == 0)
        printf("Elemento nao encontrado\n");
    c++;

    logOperacao(c, m, inicio);
}