#ifndef QUICK_SORT_V1_H
#define QUICK_SORT_V1_H


void troca1(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int calculaPivo1(int vetor[], int baixo, int alto) {
    return vetor[baixo];
}

int particiona1(int vetor[], int baixo, int alto) {
    int pivo = calculaPivo1(vetor, baixo, alto);
    int i = baixo - 1;
    int j = alto + 1;

    while (1) {
        do {
            i++;
        } while (vetor[i] < pivo);

        do {
            j--;
        } while (vetor[j] > pivo);

        if (i >= j) {
            return j;
        }

        troca1(&vetor[i], &vetor[j]);
    }
}

// Função QuickSort com recursão de cauda
void Quick_Sort_V1(int vetor[], int baixo, int alto) {
    while (baixo < alto) {
        int indicePivo = particiona1(vetor, baixo, alto);

        if (indicePivo - baixo < alto - indicePivo) {
            Quick_Sort_V1(vetor, baixo, indicePivo);
            baixo = indicePivo + 1;
        } else {
            Quick_Sort_V1(vetor, indicePivo + 1, alto);
            alto = indicePivo;
        }
    }
}


#endif
