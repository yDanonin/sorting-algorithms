#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include "algs/sorting_algorithms.h"

FILE *openFile(char file_name[]) {
    // Trocar a string abaixo dependendo do diretório de onde foi baixado e onde está armazenado os dados
    // ex: "/home/fabiano/CLionProjects/sorting-algorithms/data/"
    // para descobrir o caminho do diretório ao baixar esse projeto, se estiver no linux pode executar os seguintes comandos:
    // cd data
    // pwd
    char directory[128] = "/home/fabiano/CLionProjects/sorting-algorithms/data/";
    strncat(directory, file_name, sizeof(directory) - strlen(directory) - 1);

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
    struct timespec start, end;
    double cpu_time_used;

    clock_gettime(CLOCK_MONOTONIC, &start);
    sortFunction(arr, size);
    clock_gettime(CLOCK_MONOTONIC, &end);

    cpu_time_used = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;

    printf("%s took %f seconds to execute\n", algorithmName, cpu_time_used);
}

int main() {
    FILE *file;
    char file_name[] = "dtaleat50kdup1.txt";
    char line[100];
    int dataArray[50000];
    int index = 0;

    file = openFile(file_name);

    printf("\n");
    while (fgets(line, sizeof(line), file) != NULL) {
        int value = atoi(line);
        dataArray[index] = value;
        index++;
    }

    fclose(file);

    testSortingAlgorithm("Quick Sort", quick_sort, dataArray, sizeof(dataArray) / sizeof(dataArray[0]));
    testSortingAlgorithm("Binary Insertion Sort", insertion_sort, dataArray, sizeof(dataArray) / sizeof(dataArray[0]));
    testSortingAlgorithm("Radix Sort LSD", radix_sort_lsd_start, dataArray, sizeof(dataArray) / sizeof(dataArray[0]));
    testSortingAlgorithm("Radix Sort MSD", radix_sort_msd_start, dataArray, sizeof(dataArray) / sizeof(dataArray[0]));

    return 0;
}
