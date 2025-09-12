#include <stdio.h>
#include "Pessoa.h"

void menuPrincipal();
void menuInserir(Pessoa** primeiro, Pessoa** ultimo, int *tamanhoLista);
void menuRemover(Pessoa** primeiro, Pessoa** ultimo, int *tamanhoLista);
void imprimeLista(Pessoa* lista);

void leArquivo(Pessoa** primeiro, Pessoa** ultimo, int* tamanhoLista);
void salvaArquivo(Pessoa* lista);

void novoElemento(Pessoa** primeiro, Pessoa** ultimo, int* tamanhoLista, int pos);
void removeElemento(Pessoa** primeiro, Pessoa** ultimo, int* tamanhoLista, int pos);
void procurarElemento(Pessoa* primeiro);

int main(void) {
    menuPrincipal();
    return 0;
}

void menuPrincipal() {
    int opcao = 1;
    Pessoa* primeiro = NULL;
    Pessoa* ultimo = NULL;
    int tamanhoLista = 0;

    while (opcao != 0) {
        printf("\n");
        printf("===============================\n");
        printf("Lista Sequencial\n");
        printf("1 - Inserir\n");
        printf("2 - Remover\n");
        printf("3 - Procurar\n");
        printf("4 - Mostrar lista\n");
        printf("5 - Salvar\n");
        printf("0 - Sair\n");
        printf("===============================\n");
        scanf("%d", &opcao);
        getchar();
        printf("\n");

        switch (opcao) {
            case 1:
                menuInserir(&primeiro, &ultimo, &tamanhoLista);
                break;
            case 2:
                menuRemover(&primeiro, &ultimo, &tamanhoLista);
                break;
            case 3:
                procurarElemento(primeiro);
                break;
            case 4:
                imprimeLista(primeiro);
                break;
            case 5:
                salvaArquivo(primeiro);
                break;
        }
    }
}

void menuInserir(Pessoa** primeiro, Pessoa** ultimo, int *tamanhoLista) {
    int opcao = 1;
    int posicao;
    while (opcao != 0) {
        printf("\n");
        printf("===============================\n");
        printf("Lista Sequencial\n");
        printf("1 - Ler arquivo\n");
        printf("2 - Inserir no inicio da lista\n");
        printf("3 - Inserir no fim da lista\n");
        printf("4 - Inserir em N\n");
        printf("0 - Voltar\n");
        printf("===============================\n");
        scanf("%d", &opcao);
        getchar();
        printf("\n");
        switch (opcao) {
            case 1:
                leArquivo(primeiro, ultimo, tamanhoLista);
                break;
            case 2:
                novoElemento(primeiro, ultimo, tamanhoLista, 0);
                break;
            case 3:
                novoElemento(primeiro, ultimo, tamanhoLista, *tamanhoLista);
                break;
            case 4:
                printf("Digite a posicao do novo elemento\n");
                scanf("%d", &posicao);
                getchar();
                novoElemento(primeiro, ultimo, tamanhoLista, posicao);
                break;
            default:
                break;

        }
    }
}

void menuRemover(Pessoa** primeiro, Pessoa** ultimo, int *tamanhoLista) {
    int opcao = 1;
    int posicao;
    while (opcao != 0) {
        printf("\n");
        printf("===============================\n");
        printf("Lista Sequencial\n");
        printf("1 - Remove primeiro elemento\n");
        printf("2 - Remove ultimo elemento\n");
        printf("3 - Remove elemento N\n");
        printf("0 - Voltar\n");
        printf("===============================\n");
        scanf("%d", &opcao);
        getchar();
        printf("\n");
        switch (opcao) {
            case 1:
                removeElemento(primeiro, ultimo, tamanhoLista, 0);
                break;
            case 2:
                removeElemento(primeiro, ultimo, tamanhoLista, *tamanhoLista-1);
                break;
            case 3:
                printf("Digite a posicao do elemento a ser removido\n");
                scanf("%d", &posicao);
                getchar();
                removeElemento(primeiro, ultimo, tamanhoLista, posicao);
                break;
            default:
                break;
        }
    }
}

void imprimeLista(Pessoa* lista) {
    Pessoa* atual = lista;
    while (atual != NULL) {
        printf("Nome: %s, RG: %ld\n", atual->nome, atual->rg);
        atual = atual->proximo;
    }
}

