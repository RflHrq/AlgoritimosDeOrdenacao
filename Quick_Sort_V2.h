#ifndef QUICK_SORT_V2_H
#define QUICK_SORT_V2_H

void troca2(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int calculaPivo2(int vetor[], int baixo, int alto) {
    int meio = baixo + (alto - baixo) / 2;
    int pivo = vetor[meio];
    return pivo;
}

int particiona2(int vetor[], int baixo, int alto) {
    int pivo = calculaPivo2(vetor, baixo, alto);
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

        troca2(&vetor[i], &vetor[j]);
    }
}

void Quick_Sort_V2(int vetor[], int baixo, int alto) {
    while (baixo < alto) {
        int indicePivo = particiona2(vetor, baixo, alto);

        if (indicePivo - baixo < alto - indicePivo) {
            Quick_Sort_V2(vetor, baixo, indicePivo);
            baixo = indicePivo + 1;
        } else {
            Quick_Sort_V2(vetor, indicePivo + 1, alto);
            alto = indicePivo;
        }
    }
}

#endif
