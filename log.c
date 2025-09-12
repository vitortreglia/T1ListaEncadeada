//
// Created by Vitor Aguiar Treglia on 08/09/25.
//

#include <stdio.h>
#include <time.h>

void logOperacao(int c, int m, clock_t inicio) {
    printf("Operacao concluida. %d comparacoes e %d movimentacoes realizadas.\n", c, m);
    clock_t fim = clock();
    printf("Tempo de execucao: %fs\n", (float)(fim - inicio) / CLOCKS_PER_SEC);
    getchar();
}
