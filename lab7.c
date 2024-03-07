#include <stdio.h>

void selectionSort(int arr[], int n) {
    int i, j, minIndex, temp, swaps = 0;

    // Iterate through the array
    for (i = 0; i < n - 1; i++) {
        // Find the index of the minimum element in the unsorted part of the array
        minIndex = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // Swap the minimum element with the first element of the unsorted part
        temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
        swaps++;
        printf("%d times %d is swapped\n", swaps, arr[i]);
    }

    printf("total %d of swaps \n", swaps);
}

void bubbleSort(int arr[], int n) {
    int i, j, temp, count = 0, swaps = 0;

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swaps++;
                printf("%d times %d is swapped\n", swaps, arr[j]);

            }
        }
    }

    printf("total %d of swaps\n", swaps);
}

int main() {
    int arr[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int arr2[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Array 1:\n");
    bubbleSort(arr, n);

    printf("\nArray 2:\n");
    selectionSort(arr2, n);

    return 0;
}
