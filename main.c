#include <stdio.h>
#include "quick_sort.h"


int main() {
    int arr[] = {12, 45, 1, 78, 5, 9, 23};
    int tamanho = sizeof(arr) / sizeof(arr[0]);

    printf("Vetor original:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    quick_sort(arr, tamanho);

    printf("Vetor ordenado:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
