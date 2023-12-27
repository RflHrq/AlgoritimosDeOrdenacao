#ifndef GERAR_ARQUIVO_H
#define GERAR_ARQUIVO_H

extern int Opcao_Menu;
extern int Opcao_Tamanho_Menu;
extern char Opcao_Algoritimo_Menu[50];
extern char Opcao_Menu_Char[50];

void gerar_arquivo_randomico(){

    printf("\nArquivo Aleatorio esta Sendo Gerado\n\n");

    int valor = 1, i=0, j=0, igual = 0;
    int *vetor;
    char caminhoCompleto[100]; // Use um tamanho adequado para o caminho completo
    snprintf(caminhoCompleto, sizeof(caminhoCompleto), "%s/Entradas", Opcao_Algoritimo_Menu);
    char caminhoCompleto2[100]; // Use um tamanho adequado para o caminho completo
    snprintf(caminhoCompleto2, sizeof(caminhoCompleto2), "%s/Random", caminhoCompleto);

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

    vetor = (int *)malloc(Opcao_Tamanho_Menu * sizeof(int));
    if (vetor == NULL) {
        printf("Erro ao alocar memória para o vetor.\n");
        exit(0);
    }
    // Gerando Numeros Aleatorios sem repetição
    srand(time(NULL));
    do{
        long long aleatorio = (long long)(1+rand()) * (1+rand()) * (1+rand()) * (1+rand());
            vetor[i] = 1+aleatorio%(4000000);
            igual = 0;
            for(int j=0; j<i; j++){
                if(vetor[j]==vetor[i]){
                    igual = 1;
                }
            }
            if(igual==0){
                i++;
            }
    }while(i<Opcao_Tamanho_Menu);

    char caminho_arquivo[200];
    sprintf(caminho_arquivo, "C:/PA/%s/EntradaRandom%d.txt", caminhoCompleto2, Opcao_Tamanho_Menu);
    FILE *arquivo = fopen(caminho_arquivo, "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        free(vetor);
        exit(0);
    }
    fprintf(arquivo, "%d\n", Opcao_Tamanho_Menu);
    for(int i=0; i<Opcao_Tamanho_Menu; i++){
        fprintf(arquivo, "%08d\n", vetor[i]);
    }
    fclose(arquivo);
    //imprimir valores na tela

    printf("\nNumeros Randomicos:\n\n");
    for(int i=0; i<Opcao_Tamanho_Menu; i++){
        printf("%08d,\n ", vetor[i]);
    }
    printf("\nArquivo Aleatorio Gerado com Sucesso\n\n");
    printf("------------------------------------------------------------------------------------------------------------------------");
    free(vetor);
}

void gerar_arquivo_crescente(){
    printf("Arquivo Crescente esta Sendo Gerado\n\n");

    int valor = 1, i=0;
    int *vetor;

    char caminhoCompleto[100]; // Use um tamanho adequado para o caminho completo
    snprintf(caminhoCompleto, sizeof(caminhoCompleto), "%s/Entradas", Opcao_Algoritimo_Menu);
    char caminhoCompleto2[100]; // Use um tamanho adequado para o caminho completo
    snprintf(caminhoCompleto2, sizeof(caminhoCompleto2), "%s/Crescente", caminhoCompleto);

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

    vetor = (int *)malloc(Opcao_Tamanho_Menu * sizeof(int));
    if (vetor == NULL) {
        printf("Erro ao alocar memória para o vetor.\n");
        exit(0);
    }

    for(int i=0; i<Opcao_Tamanho_Menu; i++){
        vetor[i] = i+1;
    }
    char caminho_arquivo[200];
    sprintf(caminho_arquivo, "C:/PA/%s/EntradaCrescente%d.txt", caminhoCompleto2, Opcao_Tamanho_Menu);
    FILE *arquivo = fopen(caminho_arquivo, "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        free(vetor);
        exit(0);
    }
    fprintf(arquivo, "%d\n", Opcao_Tamanho_Menu);
    for(int i=0; i<Opcao_Tamanho_Menu; i++){
        fprintf(arquivo, "%08d\n", vetor[i]);
    }
    fclose(arquivo);
    printf("\nNumeros Crescentes:\n\n");
    for(int i=0; i<Opcao_Tamanho_Menu; i++){
        printf("%08d,\n ", vetor[i]);
    }
    printf("Arquivo Crescente Gerado com Sucesso\n\n");
    printf("------------------------------------------------------------------------------------------------------------------------");
    free(vetor);
}

void gerar_arquivo_decrescente(){
    printf("Arquivo Decrescente esta Sendo Gerado\n");

    int valor = 1, i=0, j=0;
    int *vetor;

      char caminhoCompleto[100]; // Use um tamanho adequado para o caminho completo
    snprintf(caminhoCompleto, sizeof(caminhoCompleto), "%s/Entradas", Opcao_Algoritimo_Menu);
    char caminhoCompleto2[100]; // Use um tamanho adequado para o caminho completo
    snprintf(caminhoCompleto2, sizeof(caminhoCompleto2), "%s/Decrescente", caminhoCompleto);

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

    vetor = (int *)malloc(Opcao_Tamanho_Menu * sizeof(int));
    if (vetor == NULL) {
        printf("Erro ao alocar memória para o vetor.\n");
        exit(0);
    }

    int valorInicial = Opcao_Tamanho_Menu;
    for(int i=0; i<Opcao_Tamanho_Menu; i++){
        vetor[i] = valorInicial;
        valorInicial--;
    }

    char caminho_arquivo[200];
    sprintf(caminho_arquivo, "C:/PA/%s/EntradaDecrescente%d.txt", caminhoCompleto2 ,Opcao_Tamanho_Menu);
    FILE *arquivo = fopen(caminho_arquivo, "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        free(vetor);
        exit(0);
    }
    fprintf(arquivo, "%d\n", Opcao_Tamanho_Menu);
    for(int i=0; i<Opcao_Tamanho_Menu; i++){
        fprintf(arquivo, "%08d\n", vetor[i]);
    }
    fclose(arquivo);
    printf("\nNumeros Decrescentes:\n\n");
    for(int i=0; i<Opcao_Tamanho_Menu; i++){
        printf("%08d,\n ", vetor[i]);
    }
    printf("\nArquivo Decrescente Gerado com Sucesso\n\n");
    printf("------------------------------------------------------------------------------------------------------------------------");
    free(vetor);
}

#endif



