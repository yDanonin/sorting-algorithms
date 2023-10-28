#include <stdio.h>
#include "algs/sorting_algorithms.h"

int main() {
    int arr[] = { 37, 23, 0, 17, 12, 72, 31, 46, 100, 88, 54 };
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Vetor original:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("------------------------------------- Starting Quicksort ------------------------------------- ");

    printf("\n");

    quick_sort(arr, size);

    printf("------------------------------------- Quicksort Done ------------------------------------- ");

    printf("\n");
    printf("\n");

    printf("Vetor ordenado:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
