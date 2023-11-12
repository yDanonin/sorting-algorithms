#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include "algs/sorting_algorithms.h"

FILE *openFile(char file_name[]) {
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

    return file;
}

void testSortingAlgorithm(const char* algorithmName, void (*sortFunction)(int[], int), int arr[], int size) {
    clock_t start, end;
    double cpu_time_used;

    start = clock();
    sortFunction(arr, size);
    end = clock();

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("%s took %f seconds to execute\n", algorithmName, cpu_time_used);
}

int main() {
    FILE *file;
    char file_name[] = "dtdecre10uni0.txt10uni1.txt";
    char line[100];
    int dataArray[100];
    int index = 0;

    file = openFile(file_name);

    printf("\n");
    while (fgets(line, sizeof(line), file) != NULL) {
        int value = atoi(line);
        dataArray[index] = value;
        index++;
        printf("%s", line);
    }

    printf("Dados armazenados no array:\n");
    for (int i = 0; i < index; i++) {
        printf("%d\n", dataArray[i]);
    }
    fclose(file);

    testSortingAlgorithm("Quick Sort", quick_sort, dataArray, sizeof(dataArray) / sizeof(dataArray[0]));
//    testSortingAlgorithm("Binary Insertion Sort", insertion_sort, dataArray, sizeof(dataArray) / sizeof(dataArray[0]));
//    testSortingAlgorithm("Radix Sort LSD", radix_sort_lsd_start, dataArray, sizeof(dataArray) / sizeof(dataArray[0]));
//    testSortingAlgorithm("Radix Sort MSD", radix_sort_msd_start, dataArray, sizeof(dataArray) / sizeof(dataArray[0]));

    return 0;
}
