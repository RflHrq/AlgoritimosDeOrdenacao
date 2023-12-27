#ifndef BUBBLE_SORT_MELHORADO_H
#define BUBBLE_SORT_MELHORADO_H

double bubble_sort_melhorado(int *vetor, int tamanho){
    int memoria, troca=1, i, j;
    clock_t inicio, fim;
    double tempo = 0.0;

    inicio = clock();
    for(j=tamanho-1; (j>=1) && (troca==1); j--){
		troca=0;
		for(i=0; i<j; i++){
				if(vetor[i]>vetor[i+1]){
					memoria=vetor[i];
					vetor[i]=vetor[i+1];
					vetor[i+1]=memoria;
					troca=1;
			}
		}
	}
    fim = clock();

    tempo = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    return tempo;
}
#endif
