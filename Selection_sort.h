
#ifndef SELECTION_SORT_H
#define SELECTION_SORT_H

double selection_sort(int *vetor, int tamanho) {
    int i, j, mi, aux;
    clock_t inicio, fim;
    double tempo = 0.0; // Inicializando tempo com zero

    inicio = clock();
    for (i = 0; i < (tamanho-1); i++){
        mi = i;
        for (j = (i+1); j < tamanho; j++) {
            if(vetor[j] < vetor[mi])
            mi = j;
        }
        if (i != mi) {
            aux = vetor[i];
            vetor[i] = vetor[mi];
            vetor[mi] = aux;
        }
    }
    fim = clock();

    tempo = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    return tempo;
}


#endif
