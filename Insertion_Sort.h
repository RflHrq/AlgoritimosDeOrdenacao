#ifndef INSERTION_SORT_H
#define INSERTION_SORT_H

double insertion_sort(int *vetor, int tamanho) {
    int valor, chave, i, j;
    clock_t inicio, fim;
    double tempo = 0.0; // Inicializando tempo com zero

    inicio = clock();

    for (i = 1; i < tamanho; i++) {
        chave = vetor[i];
        j = i - 1;
        while (j >= 0 && vetor[j] > chave) {
            vetor[j + 1] = vetor[j];
            j = j - 1;
        }
        vetor[j + 1] = chave;
    }

    fim = clock();
    tempo = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    return tempo;
}


#endif
