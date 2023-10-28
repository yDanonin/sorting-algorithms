#include <stdio.h>
#include <stdlib.h>
#include "sorting_algorithms.h"

#define MAX_DIGITS 10 // Maximum number of digits in an integer (For the MSD Radix Sort)

// Function to find the maximum value in an array
int find_max(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Function to get the digit at a specific position (For the MSD Radix Sort)
int get_digit(int num, int position) {
    int divisor = 1;
    for (int i = 0; i < position; i++) {
        divisor *= 10;
    }
    return (num / divisor) % 10;
}


// Function to perform LSD (Least Significant Digit) Radix Sort
// No Radix Sort LSD, você começa a ordenação do digito mais à direita
// (o digito menos significante, LSD)
// e se movimenta para o dígito mais a esquerda.
void radix_sort_lsd_start(int arr[], int n) {
    int max = find_max(arr, n);
    
    for (int exp = 1; max / exp > 0; exp *= 10) {
        int output[n];
        int count[10] = {0};
        
        // Count the occurrences of each digit
        for (int i = 0; i < n; i++) {
            count[(arr[i] / exp) % 10]++;
        }
        
        // Calculate the cumulative count
        for (int i = 1; i < 10; i++) {
            count[i] += count[i - 1];
        }
        
        // Build the output array
        for (int i = n - 1; i >= 0; i--) {
            output[count[(arr[i] / exp) % 10] - 1] = arr[i];
            count[(arr[i] / exp) % 10]--;
        }
        
        // Copy the output array back to the original array
        for (int i = 0; i < n; i++) {
            arr[i] = output[i];
        }
    }
}

// Function to perform MSD (Most Significat Digit) Radix Sort on a subarray
// No Radix Sort MSD, você começa a ordenação do digito mais à esquerda
// (o digito mais significante, MSD)
// e se movimenta para o dígito mais a direita.
void msd_radix_sort(int arr[], int left, int right, int position) {
    if (left >= right || position < 0) {
        return;
    }

    int max = find_max(arr + left, right - left + 1);

    // Create buckets for each digit (0-9)
    int *buckets[10];
    for (int i = 0; i < 10; i++) {
        buckets[i] = (int *)malloc(sizeof(int) * (right - left + 1));
    }

    // Distribute elements into buckets based on the current digit
    int counts[10] = {0};
    for (int i = left; i <= right; i++) {
        int digit = get_digit(arr[i], position);
        buckets[digit][counts[digit]++] = arr[i];
    }

    // Copy elements back into the original array
    int index = left;
    for (int i = 0; i < 10; i++) {
        msd_radix_sort(buckets[i], 0, counts[i] - 1, position - 1);
        for (int j = 0; j < counts[i]; j++) {
            arr[index++] = buckets[i][j];
        }
        free(buckets[i]);
    }
}

// Function to initiate MSD Radix Sort
void radix_sort_msd_start(int arr[], int n) {
    int max = find_max(arr, n);
    msd_radix_sort(arr, 0, n - 1, MAX_DIGITS - 1);
}

//int main() {
//    // LSD Radix Sort
//    int arr1[] = {170, 45, 75, 90, 802, 24, 2, 66};
//    int n1 = sizeof(arr1) / sizeof(arr1[0]);
//
//    printf("Original Array (LSD): ");
//    for (int i = 0; i < n1; i++) {
//        printf("%d ", arr1[i]);
//    }
//    printf("\n");
//
//    radix_sort_lsd_start(arr1, n1);
//
//    printf("Sorted Array (LSD): ");
//    for (int i = 0; i < n1; i++) {
//        printf("%d ", arr1[i]);
//    }
//    printf("\n");
//
//    // MSD Radix Sort
//    int arr2[] = {170, 45, 75, 90, 802, 24, 2, 66};
//    int n2 = sizeof(arr2) / sizeof(arr2[0]);
//
//    printf("Original Array (MSD): ");
//    for (int i = 0; i < n2; i++) {
//        printf("%d ", arr2[i]);
//    }
//    printf("\n");
//
//    radix_sort_msd_start(arr2, n2);
//
//    printf("Sorted Array (MSD): ");
//    for (int i = 0; i < n2; i++) {
//        printf("%d ", arr2[i]);
//    }
//    printf("\n");
//
//    return 0;
//}