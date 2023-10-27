#include<stdio.h>
#include<stdlib.h>
#include "quick_sort.h"

//Define o tam que o vetor tem
#define tamanho 7

//Algoritmo de ordenacao QuickSort
void quick_sort(int* v, int tam) {
    int j = tam, k;
    if (tam <= 1)
        return;
    else {
        int x = v[0];
        int a = 1;
        int b = tam - 1;
        do {
            while ((a < tam) && (v[a] <= x))
                a++;
            while (v[b] > x)
                b--;
            if (a < b) { // faz troca
                int temp = v[a];
                v[a] = v[b];
                v[b] = temp;
                a++;
                b--;
            }
            for (k = 0; k < j; k++)
                printf("%d ", v[k]);
            printf("\n");
        } while (a <= b);
        // troca pivo
        v[0] = v[b];
        v[b] = x;
        // ordena sub-vetores restantes
        quick_sort(v, b);
        quick_sort(&v[a], tam - a);
        for (k = 0; k < j; k++)
            printf("%d ", v[k]);
        printf("\n");
    }
}