#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

#ifdef _WIN32
#include <windows.h>
#else
#include <sys/stat.h>
#endif

#include "Shell_Sort.h"
#include "Selection_sort.h"
#include "Bubble_Sort.h"
#include "Bubble_Sort _Melhorado.h"
#include "Insertion_Sort.h"
#include "Quick_Sort_V1.h"
#include "Quick_Sort_V2.h"
#include "Quick_Sort_V3.h"
#include "Quick_Sort_V4.h"
#include "Merge_Sort.h"
#include "HeapSort.h"
#include "Filas.h"
#include "Gerar_arquivo.h"


int Opcao_Alg_num = 0;
int Opcao_Menu;
int Opcao_Tamanho_Menu = 0;
char Opcao_Algoritimo_Menu[50];
char Opcao_Menu_Char[50];

void menu_principal();
void menu_tipo_ordem();
void menu_tamanho();
void menu_seleciona_arquivo();
void gerar_arquivo();
void ordenar();

int main(){
    menu_principal();
    return 0;
}

void menu_principal(){
    int valor = 1;
    int *original_arr = NULL;  // Ponteiro para o vetor alocado dinamicamente
    int n = 10;  // Tamanho inicial do vetor
    original_arr = (int *)malloc(n * sizeof(int));

    do{
        printf("\n####################################\n");
        printf("##         MENU PRINCIPAL         ##\n");
        printf("####################################\n\n");
        printf("1: Algoritmo Insertion Sort\n2: Algoritmo Selection Sort\n3: Algoritmo Shell Sort");
        printf("\n4: Algoritmo Bubble Sort\n5: Algoritmo Bubble Sort Melhorado\n6: Algoritmo Quick Sort com Pivo no Primeiro Elemento");
        printf("\n7: Algoritmo Quick Sort com Pivo da Media dos Elementos\n8: Algoritmo Quick Sort com Pivo da Mediana de 3 Elementos");
        printf("\n9: Algoritmo Quick Sort com Pivo Randomico \n10: Algoritmo Merge Sort\n11: Algoritmo Heapsort \n12: Heap Minimo \n13: Heap Extract Min\n14: Heap Increase Key\n15: Heap Insert\n0: Sair\n\n");
        printf("\nEscolha uma Opcao: ");
        scanf("%d", &valor);
        printf("------------------------------------------------------------------------------------------------------------------------");
        if(valor < 0 || valor > 15){
            printf("Opcao invalida. Favor digitar uma opcao valida.\n\n");
        }
    } while(valor < 0 || valor > 15);
        switch (valor) {
        case 1:
            strcpy(Opcao_Algoritimo_Menu, "Insertion Sort");
        break;
        case 2:
            strcpy(Opcao_Algoritimo_Menu, "Selection Sort");
        break;
        case 3:
            strcpy(Opcao_Algoritimo_Menu, "Shell Sort");
        break;
        case 4:
            strcpy(Opcao_Algoritimo_Menu, "Bubble Sort");
        break;
        case 5:
            strcpy(Opcao_Algoritimo_Menu, "Bubble Sort Melhorado");
        break;
        case 6:
            strcpy(Opcao_Algoritimo_Menu, "Quick Sort com Pivo no Primeiro Elemento");
        break;
        case 7:
            strcpy(Opcao_Algoritimo_Menu, "Quick Sort com Pivo da Media dos Elementos");
        break;
        case 8:
            strcpy(Opcao_Algoritimo_Menu, "Quick Sort com Pivo da Mediana de 3 Elementos");
        break;
        case 9:
            strcpy(Opcao_Algoritimo_Menu, "Quick Sort com Pivo Randomico");
        break;
        case 10:
            strcpy(Opcao_Algoritimo_Menu, "Merge Sort");
        break;
        case 11:
            strcpy(Opcao_Algoritimo_Menu, "Heapsort");
        break;
        case 12:
            printf("Heap Minimo\n\n");
            printf("Vetor Original: ");
            for (int i = 0; i < 10; i++) {
                original_arr[i] = rand() % 100;
                printf("%d ", original_arr[i]);
            }
            printf("\n");

            build_min_heap(original_arr, 10);
            printf("Vetor Chamando Build: ");
            for (int i = 0; i < 10; i++){
                printf("%d ", original_arr[i]);
            }
            printf("\n");

            printf("Elemeto Minimo: %d\n", heap_minimum(original_arr));
            printf("------------------------------------------------------------------------------------------------------------------------");
        break;
        case 13:
            printf("Heap Extract Min\n\n");
            printf("Vetor Original: ");
            for (int i = 0; i < 10; i++) {
                original_arr[i] = rand() % 100;
                printf("%d ", original_arr[i]);
            }
            printf("\n");

            build_min_heap(original_arr, 10);
            printf("Vetor Chamando Build: ");
            for (int i = 0; i < 10; i++){
                printf("%d ", original_arr[i]);
            }
            printf("\n");

            int extracted_min = heap_extract_min(original_arr, &n);
            printf("Elemento Minimo: %d\n", extracted_min);
            printf("Vetor Chamando Min_Heapfy: ");
            for (int i = 0; i < n; i++){
                printf("%d ", original_arr[i]);
            }
            printf("\n------------------------------------------------------------------------------------------------------------------------");
        break;
        case 14:
            printf("Heap Increase Key\n\n");
            printf("Vetor Original: ");
            for (int i = 0; i < 10; i++) {
                original_arr[i] = rand() % 100;
                printf("%d ", original_arr[i]);
            }
            printf("\n");

            build_min_heap(original_arr, 10);
            printf("Vetor Chamando Build: ");
            for (int i = 0; i < 10; i++){
                printf("%d ", original_arr[i]);
            }
            printf("\n");

            int posicao;
            printf("Determine a posicao para inserir o valor 1000: ");
            scanf("%d", &posicao);

            heap_increase_key(original_arr, posicao, 1000);

            printf("Vetor apos a Insercao: ");
            for (int i = 0; i < 10; i++){
                printf("%d ", original_arr[i]);
            }

            printf("\n------------------------------------------------------------------------------------------------------------------------");
        break;
        case 15:
            printf("Heap Insert\n\n");
            printf("Vetor Original: ");
            for (int i = 0; i < 10; i++) {
                original_arr[i] = rand() % 100;
                printf("%d ", original_arr[i]);
            }
            printf("\n");
            max_heap_insert(&original_arr, &n, 1000);
            printf("Vetor apos a Insercao: ");
            for (int i = 0; i < 11; i++){
                printf("%d ", original_arr[i]);
            }
            printf("\n------------------------------------------------------------------------------------------------------------------------");
        break;
        default:
            exit(0);
        break;
        }
    free(original_arr);
    Opcao_Alg_num = valor;
    if (valor == 12 || valor == 13 || valor == 14 || valor == 15){
        menu_principal();
    }else{
        menu_tipo_ordem();
    }
}


void menu_tipo_ordem(){
    int valor = 1;
    do{
        printf("\n####################################\n");
        printf("##    MENU ORDEM DOS VALORES      ##\n");
        printf("####################################\n\n");
        printf("1: Numeros Crescentes\n2: Numeros Decrescentes\n3: Numeros Randomicos\n4: Voltar ao Menu Principal\n\n");
        printf("Escolha uma Opcao de Ordem: ");
        scanf("%d", &valor);
        printf("------------------------------------------------------------------------------------------------------------------------");
        Opcao_Menu = valor;
        if(valor < 1 || valor > 4){
            printf("Opcao invalida. Favor digitar uma opcao valida.\n");
        }
    } while(valor < 1 || valor > 4);
    switch (valor) {
        case 1:
            strcpy(Opcao_Menu_Char, "Crescente");
        break;
        case 2:
            strcpy(Opcao_Menu_Char, "Decrescente");
        break;
        case 3:
            strcpy(Opcao_Menu_Char, "Random");
        break;
    }

    if(valor == 4){
        menu_principal();
    } else {
        menu_tamanho();
    }
}

void menu_tamanho(){
    int valor = 1;
    do{
        printf("\n####################################\n");
        printf("##      TAMANHO DA INSTANCIA      ##\n");
        printf("####################################\n\n");
        printf("1: 10(Dez)\n2: 100(Cem)\n3: 1000(Mil)\n4: 10000(Dez Mil)\n5: 100000(Cem Mil)\n6: 1000000(Um Milhao)\n7: Voltar ao Menu anterior\n\n");
        printf("Escolha uma Opcao de Tamanho: ");
        scanf("%d", &valor);
        printf("------------------------------------------------------------------------------------------------------------------------");
        if(valor < 1 || valor > 7){
            printf("Opcao invalida. Favor digitar uma opcao valida.\n");
        }

    } while(valor < 1 || valor > 7);

    if(valor == 7){
        menu_tipo_ordem();
    } else {
        Opcao_Tamanho_Menu = pow(10, valor);
        menu_seleciona_arquivo();
    }
}


void menu_seleciona_arquivo(){
    int valor = 1;
    do{
        printf("\n####################################\n");
        printf("##        OPCAO DE ARQUIVO        ##\n");
        printf("####################################\n\n");
        printf("1: Usar Ordem Existente\n2: Gerar Nova Ordem\n3: Voltar ao Menu anterior\n\n");
        printf("Escolha uma Opcao: ");
        scanf("%d", &valor);
        printf("------------------------------------------------------------------------------------------------------------------------");
        if(valor < 1 || valor > 3){
            printf("Opcao invalida. Favor digitar uma opcao valida.\n");
        }
    } while(valor < 1 || valor > 3);

    if(valor == 3){
        menu_tamanho();
    } else if(valor == 2){
        gerar_arquivo();
    } else {
        ordenar();
    }
}

void gerar_arquivo(){
    int valor = 0;
    do{
        printf("\n####################################\n");
        printf("##          GERAR ARQUIVO         ##\n");
        printf("####################################\n\n");
        printf("1: Gerar Sequencia para a instancia Selecionada\n2: Gerar Sequencia para todas as instancias\n3: Voltar ao Menu anterior\n\n");
        printf("Escolha uma Opcao para Gerar o Arquivo: ");
        scanf("%d", &valor);
        printf("------------------------------------------------------------------------------------------------------------------------");
        if(valor < 1 || valor > 3){
            printf("Opcao invalida. Favor digitar uma opcao valida.\n");
        }
    }while(valor < 1 || valor > 3);

    if(valor == 3){
        menu_seleciona_arquivo();
    }else{

        if (Opcao_Menu == 3 || valor == 2) {
            gerar_arquivo_randomico();
        }

        if (Opcao_Menu == 1 || valor == 2) {
            gerar_arquivo_crescente();
        }

        if (Opcao_Menu == 2 || valor == 2) {
            gerar_arquivo_decrescente();
        }

        ordenar();
    }
}

void ordenar(){
    int valor, tamanho;
    double tempo_execucao;

    char caminho_arquivo_entrada[200];
    char caminho_arquivo_saida[200];
    char caminho_arquivo_tempo[200];
    char caminhoCompleto[100]; // Use um tamanho adequado para o caminho completo
    snprintf(caminhoCompleto, sizeof(caminhoCompleto), "%s/Entradas", Opcao_Algoritimo_Menu);
    char caminhoCompleto2[100]; // Use um tamanho adequado para o caminho completo
    snprintf(caminhoCompleto2, sizeof(caminhoCompleto2), "%s/%s", caminhoCompleto, Opcao_Menu_Char);

    printf("Gerando Arquivo %s de Ordem %s de %d Instancias.\n",Opcao_Algoritimo_Menu, Opcao_Menu_Char,  Opcao_Tamanho_Menu);
    sprintf(caminho_arquivo_entrada, "C:/PA/%s/Entrada%s%d.txt",caminhoCompleto2, Opcao_Menu_Char, Opcao_Tamanho_Menu);
    FILE *arquivo_entrada = fopen(caminho_arquivo_entrada, "r");
    if (arquivo_entrada == NULL) {
        do{
            printf("Erro ao abrir o arquivo de entrada.\n");
            printf("\nDeseja gerar um novo arquivo de entrada?\n1: Sim\n2: Nao(Voltar ao Menu Principal)");
            printf("\n\nEscolha uma Opcao: ");
            scanf("%d", &valor);
            printf("------------------------------------------------------------------------------------------------------------------------");
            if(valor < 1 || valor > 2){
                printf("Opcao invalida. Favor digitar uma opcao valida.\n\n");
            }
        } while(valor < 1 || valor > 2);
        if(valor == 1){
            gerar_arquivo();
        }else{
            menu_principal();
        }
    }

    if (fscanf(arquivo_entrada, "%d", &tamanho) != 1) {
        printf("Erro ao ler o tamanho do vetor.\n");
        fclose(arquivo_entrada);
        exit(0);
    }

    int *vetor = (int *)malloc(tamanho * sizeof(int));
    if (vetor == NULL) {
        printf("Erro ao alocar memória para o vetor.\n");
        fclose(arquivo_entrada);
        exit(0);
    }

     for (int i = 0; i < tamanho; i++) {
        if (fscanf(arquivo_entrada, "%d", &vetor[i]) != 1) {
            printf("Erro ao ler um número do arquivo.\n");
            free(vetor);
            fclose(arquivo_entrada);
            exit(0);
        }
    }

    fclose(arquivo_entrada);

    switch (Opcao_Alg_num) {
        case 1:
            tempo_execucao = insertion_sort(vetor, tamanho);
        break;
        case 2:
            tempo_execucao = selection_sort(vetor, tamanho);
        break;
        case 3:
            tempo_execucao = shell_sort(vetor, tamanho);
        break;
        case 4:
            tempo_execucao = bubble_sort(vetor, tamanho);
        break;
        case 5:
            tempo_execucao = bubble_sort_melhorado(vetor, tamanho);
        break;
        case 6:{
            printf("Quick Sort com Pivo no Primeiro Elemento\n");
            clock_t inicio, fim;
            inicio = clock();
            Quick_Sort_V1(vetor, 0, tamanho - 1);
            fim = clock();
            tempo_execucao = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
        }
        break;
        case 7:
            {
            printf("Quick Sort com Pivo da Media dos Elementos\n");
            clock_t inicio, fim;
            inicio = clock();
            Quick_Sort_V2(vetor, 0, tamanho - 1);
            fim = clock();
            tempo_execucao = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
        }
        break;
        case 8:
            {
            printf("Quick Sort com Pivo da Mediana de 3 Elementos\n");
            clock_t inicio, fim;
            inicio = clock();
            Quick_Sort_V3(vetor, 0, tamanho - 1);
            fim = clock();
            tempo_execucao = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
            }
        break;
        case 9:
            {
            printf("Quick Sort com Pivo Randomico\n");
            clock_t inicio, fim;
            inicio = clock();
            Quick_Sort_V4(vetor, 0, tamanho - 1);
            fim = clock();
            tempo_execucao = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
            }
        break;
        case 10:
            {
            printf("Merge Sort\n");
            int arr_size = sizeof(vetor) / sizeof(vetor[0]);
            clock_t inicio, fim;
            inicio = clock();
            mergeSort(vetor, 0, tamanho - 1);
            fim = clock();
            tempo_execucao = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
            }
        break;
        case 11:
            {
            printf("Heapsort\n");
            int n = tamanho;
            clock_t inicio, fim;
            inicio = clock();
            heapsort(vetor, n);
            fim = clock();
            tempo_execucao = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
            }
        break;
        default:
            printf("Erro ao definir ordenacao.\n");
            free(vetor);
            menu_principal();
        break;
        }


    snprintf(caminhoCompleto, sizeof(caminhoCompleto), "%s/Saidas", Opcao_Algoritimo_Menu);
    snprintf(caminhoCompleto2, sizeof(caminhoCompleto2), "%s/%s", caminhoCompleto, Opcao_Menu_Char);

    #ifdef _WIN32
    DWORD attributes = GetFileAttributes(Opcao_Algoritimo_Menu);
    if (attributes != INVALID_FILE_ATTRIBUTES && (attributes & FILE_ATTRIBUTE_DIRECTORY)) {
        printf("A pasta ja existe.\n");
    } else {
        if (CreateDirectory(Opcao_Algoritimo_Menu, NULL) != 0) {
            printf("Pasta criada com sucesso no Windows!\n");
        } else {
            perror("Erro ao criar a pasta no Windows");
        }
    }

    DWORD pastaattributes = GetFileAttributes(caminhoCompleto);
    if (pastaattributes != INVALID_FILE_ATTRIBUTES && (pastaattributes & FILE_ATTRIBUTE_DIRECTORY)) {
        printf("A pasta ja existe.\n");
    } else {
        if (CreateDirectory(caminhoCompleto, NULL) != 0) {
            printf("Pasta criada com sucesso no Windows!\n");
        } else {
            perror("Erro ao criar a pasta no Windows");
        }
    }


    DWORD pasta2attributes = GetFileAttributes(caminhoCompleto2);
    if (pasta2attributes != INVALID_FILE_ATTRIBUTES && (pasta2attributes & FILE_ATTRIBUTE_DIRECTORY)) {
        printf("A pasta ja existe.\n");
    } else {
        if (CreateDirectory(caminhoCompleto2, NULL) != 0) {
            printf("Pasta criada com sucesso no Windows!\n");
        } else {
            perror("Erro ao criar a pasta no Windows");
        }
    }



#else
    if (access(Opcao_Algoritimo_Menu, F_OK) == 0) {
        printf("A pasta já existe.\n");
    } else {
        if (mkdir(Opcao_Algoritimo_Menu, 0777) == 0) {
            printf("Pasta criada com sucesso no Unix/Linux!\n");
        } else {
            perror("Erro ao criar a pasta no Unix/Linux");
        }
    }

    if (access(caminhoCompleto, F_OK) == 0) {
        printf("A pasta já existe.\n");
    } else {
        if (mkdir(caminhoCompleto, 0777) == 0) {
            printf("Pasta criada com sucesso no Unix/Linux!\n");
        } else {
            perror("Erro ao criar a pasta no Unix/Linux");
        }
    }

    if (access(caminhoCompleto2, F_OK) == 0) {
        printf("A pasta já existe.\n");
    } else {
        if (mkdir(caminhoCompleto2, 0777) == 0) {
            printf("Pasta criada com sucesso no Unix/Linux!\n");
        } else {
            perror("Erro ao criar a pasta no Unix/Linux");
        }
    }
#endif

    sprintf(caminho_arquivo_saida, "C:/PA/%s/Saida%s%d.txt", caminhoCompleto2, Opcao_Menu_Char, Opcao_Tamanho_Menu);
    FILE *arquivo_saida = fopen(caminho_arquivo_saida, "w");
     if (arquivo_saida == NULL) {
        printf("Erro ao abrir o arquivo de saída.\n");
        free(vetor);
        exit(0);
    }

    fprintf(arquivo_saida, "%d\n", tamanho);
    for(int i=0; i<tamanho; i++){
        fprintf(arquivo_saida, "%08d\n", vetor[i]);
    }
    fclose(arquivo_saida);
    printf("Arquivo %s de Ordem %s de %d Instancias Gerado com Sucesso.\n", Opcao_Algoritimo_Menu, Opcao_Menu_Char, Opcao_Tamanho_Menu);

    snprintf(caminhoCompleto, sizeof(caminhoCompleto), "%s/Tempos", Opcao_Algoritimo_Menu);
    snprintf(caminhoCompleto2, sizeof(caminhoCompleto2), "%s/%s", caminhoCompleto, Opcao_Menu_Char);

    #ifdef _WIN32
    DWORD wattributes = GetFileAttributes(Opcao_Algoritimo_Menu);
    if (wattributes != INVALID_FILE_ATTRIBUTES && (wattributes & FILE_ATTRIBUTE_DIRECTORY)) {
        printf("A pasta ja existe.\n");
    } else {
        if (CreateDirectory(Opcao_Algoritimo_Menu, NULL) != 0) {
            printf("Pasta criada com sucesso no Windows!\n");
        } else {
            perror("Erro ao criar a pasta no Windows");
        }
    }

    DWORD wpastaattributes = GetFileAttributes(caminhoCompleto);
    if (wpastaattributes != INVALID_FILE_ATTRIBUTES && (wpastaattributes & FILE_ATTRIBUTE_DIRECTORY)) {
        printf("A pasta ja existe.\n");
    } else {
        if (CreateDirectory(caminhoCompleto, NULL) != 0) {
            printf("Pasta criada com sucesso no Windows!\n");
        } else {
            perror("Erro ao criar a pasta no Windows");
        }
    }


    DWORD wpasta2attributes = GetFileAttributes(caminhoCompleto2);
    if (wpasta2attributes != INVALID_FILE_ATTRIBUTES && (wpasta2attributes & FILE_ATTRIBUTE_DIRECTORY)) {
        printf("A pasta ja existe.\n");
    } else {
        if (CreateDirectory(caminhoCompleto2, NULL) != 0) {
            printf("Pasta criada com sucesso no Windows!\n");
        } else {
            perror("Erro ao criar a pasta no Windows");
        }
    }



#else
    if (access(Opcao_Algoritimo_Menu, F_OK) == 0) {
        printf("A pasta já existe.\n");
    } else {
        if (mkdir(Opcao_Algoritimo_Menu, 0777) == 0) {
            printf("Pasta criada com sucesso no Unix/Linux!\n");
        } else {
            perror("Erro ao criar a pasta no Unix/Linux");
        }
    }

    if (access(caminhoCompleto, F_OK) == 0) {
        printf("A pasta já existe.\n");
    } else {
        if (mkdir(caminhoCompleto, 0777) == 0) {
            printf("Pasta criada com sucesso no Unix/Linux!\n");
        } else {
            perror("Erro ao criar a pasta no Unix/Linux");
        }
    }

    if (access(caminhoCompleto2, F_OK) == 0) {
        printf("A pasta já existe.\n");
    } else {
        if (mkdir(caminhoCompleto2, 0777) == 0) {
            printf("Pasta criada com sucesso no Unix/Linux!\n");
        } else {
            perror("Erro ao criar a pasta no Unix/Linux");
        }
    }
#endif

    sprintf(caminho_arquivo_tempo, "C:/PA/%s/Tempo%s%d.txt",caminhoCompleto2, Opcao_Menu_Char, Opcao_Tamanho_Menu);
    FILE *arquivo_tempo = fopen(caminho_arquivo_tempo, "w");
     if (arquivo_tempo == NULL) {
        printf("Erro ao abrir o arquivo de saída.\n");
        free(vetor);
        exit(0);
    }
    fprintf(arquivo_tempo, "%d\n", tamanho);
    fprintf(arquivo_tempo, "%lf\n", tempo_execucao);
    fclose(arquivo_tempo);
    free(vetor);
    printf("Arquivo de Tempo de Execucao %s de Ordem %s de %d Instancias Gerado com Sucesso com %lf segundos.\n",Opcao_Algoritimo_Menu, Opcao_Menu_Char, Opcao_Tamanho_Menu, tempo_execucao);
    printf("------------------------------------------------------------------------------------------------------------------------");
    menu_principal();
}

