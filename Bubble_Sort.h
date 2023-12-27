#ifndef BUBBLE_SORT_H
#define BUBBLE_SORT_H

double bubble_sort(int *vetor, int tamanho){
    int aux, i, j;
    clock_t inicio, fim;
    double tempo = 0.0;

    inicio = clock();
    for (j = tamanho - 1; j >= 1; j--) {
        for (i = 0; i < j; i++) {
            if (vetor[i] > vetor[i + 1]) {
                aux = vetor[i];
                vetor[i] = vetor[i + 1];
                vetor[i + 1] = aux;
            }
        }
    }
    fim = clock();

    tempo = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    return tempo;
}
#endif
