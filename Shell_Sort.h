
#ifndef SHELL_SORT_H
#define SHELL_SORT_H

double shell_sort(int *vetor, int tamanho) {
    int i, j, valor, h = 1;
    clock_t inicio, fim;
    double tempo = 0.0; // Inicializando tempo com zero

    inicio = clock();
    while(h < tamanho) {
        h = 3*h+1;
    }
    while (h > 0) {
        for(i = h; i < tamanho; i++) {
            valor = vetor[i];
            j = i;
            while (j > h-1 && valor <= vetor[j - h]) {
                vetor[j] = vetor[j - h];
                j = j - h;
            }
            vetor[j] = valor;
        }
        h = h/3;
    }
    fim = clock();

    tempo = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    return tempo;
}


#endif
