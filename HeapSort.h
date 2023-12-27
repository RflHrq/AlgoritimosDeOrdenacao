
#ifndef HEAP_SORT_H
#define HEAP_SORT_H

void MIN_HEAPIFY(int arr[], int n, int i);

void tswap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void BUILD_MIN_HEAP(int arr[], int n);

void MIN_HEAPIFY(int arr[], int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] < arr[smallest]) {
        smallest = left;
    }

    if (right < n && arr[right] < arr[smallest]) {
        smallest = right;
    }

    if (smallest != i) {
        tswap(&arr[i], &arr[smallest]);
        MIN_HEAPIFY(arr, n, smallest);
    }
}

void BUILD_MIN_HEAP(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        MIN_HEAPIFY(arr, n, i);
    }
}

void heapsort(int arr[], int n) {
    BUILD_MIN_HEAP(arr, n);

    for (int i = n - 1; i > 0; i--) {
        tswap(&arr[0], &arr[i]);
        MIN_HEAPIFY(arr, i, 0);
    }
}

#endif
