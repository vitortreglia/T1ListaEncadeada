//
// Created by Vitor Aguiar Treglia on 07/09/25.
//

#ifndef PESSOA_H
#define PESSOA_H

typedef struct Pessoa {
    long int rg;
    char nome[30];
    struct Pessoa* proximo;
} Pessoa;

#endif //PESSOA_H
