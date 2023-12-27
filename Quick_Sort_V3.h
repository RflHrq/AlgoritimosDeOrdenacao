#ifndef QUICK_SORT_V3_H
#define QUICK_SORT_V3_H

void troca3(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int encontraMediana(int vetor[], int a, int b, int c) {
    if ((vetor[a] <= vetor[b] && vetor[b] <= vetor[c]) || (vetor[c] <= vetor[b] && vetor[b] <= vetor[a]))
        return b;
    else if ((vetor[b] <= vetor[a] && vetor[a] <= vetor[c]) || (vetor[c] <= vetor[a] && vetor[a] <= vetor[b]))
        return a;
    else
        return c;
}

int calculaPivo3(int vetor[], int baixo, int alto) {
    int meio = baixo + (alto - baixo) / 2;
    int mediana = encontraMediana(vetor, baixo, meio, alto);
    return vetor[mediana];
}

int particiona3(int vetor[], int baixo, int alto) {
    int pivo = calculaPivo3(vetor, baixo, alto);
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
        troca3(&vetor[i], &vetor[j]);
    }
}

void Quick_Sort_V3(int vetor[], int baixo, int alto) {
    while (baixo < alto) {
        int indicePivo = particiona3(vetor, baixo, alto);

        if (indicePivo - baixo < alto - indicePivo) {
            Quick_Sort_V3(vetor, baixo, indicePivo);
            baixo = indicePivo + 1;
        } else {
            Quick_Sort_V3(vetor, indicePivo + 1, alto);
            alto = indicePivo;
        }
    }
}
#endif
