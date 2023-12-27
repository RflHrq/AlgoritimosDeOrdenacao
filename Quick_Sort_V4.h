#ifndef QUICK_SORT_V4_H
#define QUICK_SORT_V4_H

void troca4(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int calculaPivo4(int vetor[], int baixo, int alto) {
    int indiceAleatorio = rand() % (alto - baixo + 1) + baixo;
    return vetor[indiceAleatorio];
}

int particiona4(int vetor[], int baixo, int alto) {
    int pivo = calculaPivo4(vetor, baixo, alto);
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
        troca4(&vetor[i], &vetor[j]);
    }
}

void Quick_Sort_V4(int vetor[], int baixo, int alto) {
    while (baixo < alto) {
        int indicePivo = particiona4(vetor, baixo, alto);

        if (indicePivo - baixo < alto - indicePivo) {
            Quick_Sort_V4(vetor, baixo, indicePivo);
            baixo = indicePivo + 1;
        } else {
            Quick_Sort_V4(vetor, indicePivo + 1, alto);
            alto = indicePivo;
        }
    }
}
#endif
