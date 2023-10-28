#include <stdio.h>
#include "sorting_algorithms.h"

// A binary search based function
// to find the position
// where item should be inserted 
// in a[low..high]
int binary_search(int a[], int item, int low, int high) {
	if (high <= low)
		return (item > a[low]) ? (low + 1) : low;

	int mid = (low + high) / 2;

	if (item == a[mid])
		return mid + 1;

	if (item > a[mid])
		return binary_search(a, item, mid + 1, high);
	return binary_search(a, item, low, mid - 1);
}

// Function to sort an array a[] of size 'n'
void insertion_sort(int a[], int n) {
	int i, loc, j, k, selected;

	for (i = 1; i < n; ++i) 
	{
		j = i - 1;
		selected = a[i];

		// find location where selected should be inserted
		loc = binary_search(a, selected, 0, j);

		// Move all elements after location to create space
		while (j >= loc) 
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = selected;
	}
}

// Driver Code
//int main() {
//	int a[] = { 37, 23, 0, 17, 12, 72, 31, 46, 100, 88, 54 };
//	int n = sizeof(a) / sizeof(a[0]), i;
//
//	insertion_sort(a, n);
//
//	printf("Sorted array: \n");
//	for (i = 0; i < n; i++)
//		printf("%d ", a[i]);
//
//	return 0;
//}
