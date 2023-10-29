#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "algs/sorting_algorithms.h"

FILE openFile(char file_name[]) {
    char directory[128] = "/home/fabiano/CLionProjects/sorting-algorithms/data/";
    strncat(directory, file_name, sizeof(directory) - strlen(directory) - 1);
    printf("AQUI: %s", directory);
    if(access(directory, F_OK) == -1){
        perror("Erro ao acessar o arquivo");
    }

    FILE *file = fopen(directory, "r");

    if (file == NULL) {
        perror("Erro ao abrir o arquivo");
    }

    return *file;
}

int main() {
    FILE *file;
    char file_name[] = "ARQALEAT";
    char line[100];

    *file = openFile(file_name);

    printf("\n");
    while (fgets(line, sizeof(line), file) != NULL) {
        printf("%s", line);
    }

    fclose(file);

//    int arr[] = { 37, 23, 0, 17, 12, 72, 31, 46, 100, 88, 54 };
//    int size = sizeof(arr) / sizeof(arr[0]);
//
//    printf("Vetor original:\n");
//    for (int i = 0; i < size; i++) {
//        printf("%d ", arr[i]);
//    }
//    printf("\n");
//
//    printf("------------------------------------- Starting Quicksort ------------------------------------- ");
//
//    printf("\n");
//
//    quick_sort(arr, size);
//
//    printf("------------------------------------- Quicksort Done ------------------------------------- ");
//
//    printf("\n");
//    printf("\n");
//
//    printf("Vetor ordenado:\n");
//    for (int i = 0; i < size; i++) {
//        printf("%d ", arr[i]);
//    }
//    printf("\n");
    return 0;
}
