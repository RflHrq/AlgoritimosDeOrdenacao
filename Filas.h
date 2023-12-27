
#ifndef FILAS_H
#define FILAS_H

void swapt(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void min_heapify(int arr[], int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] < arr[smallest])
        smallest = left;

    if (right < n && arr[right] < arr[smallest])
        smallest = right;

    if (smallest != i) {
        swapt(&arr[i], &arr[smallest]);
        min_heapify(arr, n, smallest);
    }
}

void build_min_heap(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        min_heapify(arr, n, i);
}

int heap_minimum(int arr[]) {
    return arr[0];
}

int heap_extract_min(int arr[], int *n) {
    if (*n < 1) {
        printf("Heap vazio\n");
        return -1;
    }

    int mini = arr[0];
    arr[0] = arr[*n - 1];
    (*n)--;
    min_heapify(arr, *n, 0);
    return mini;
}

void heap_increase_key(int arr[], int i, int key) {
    if (key < arr[i]) {
        printf("Nova chave é menor que a chave atual\n");
        return;
    }

    arr[i] = key;
    while (i > 0 && arr[(i - 1) / 2] < arr[i]) {
        swapt(&arr[i], &arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void max_heap_insert(int **arr, int *n, int key) {
    (*n)++;

    // Redimensiona o vetor para acomodar o novo elemento
    *arr = realloc(*arr, (*n) * sizeof(int));

    // Configura o novo elemento como INT_MIN
    (*arr)[*n - 1] = INT_MIN;

    // Atualiza a heap usando heap_increase_key
    heap_increase_key(*arr, *n - 1, key);
}


#endif
