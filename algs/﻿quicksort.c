#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

//Define o tam que o vetor tem
#define tamanho 7

//Algoritmo de ordenacao QuickSort
void QuickSort(int* v, int tam) {
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
		QuickSort(v, b);
		QuickSort(&v[a], tam - a);
		for (k = 0; k < j; k++)
			printf("%d ", v[k]);
		printf("\n");
	}
}

int main()
{
	int a[] = { 37, 23, 0, 17, 12, 72, 31, 46, 100, 88, 54 };
	
	QuickSort(a, tamanho);

	printf("Sorted array: \n");
	for (int i = 0; i < tamanho; i++)
		printf("%d ", a[i]);

	return 0;
}
