// Vu Hoang Hai Pham
// Bubble Sorting + Selection Sorting

#include <stdio.h>
#include <string.h> // Include this header for memcpy function

void bubbleSort(int arr[], int n) {
    int i, j, temp, count = 0, min = arr[0], max = arr[0];

    // Find the minimum and maximum values in the array
    for (i = 1; i < n; i++) {
        if (arr[i] < min)
            min = arr[i];
        if (arr[i] > max)
            max = arr[i];
    }

    // Calculate the range of values to adjust indexing
    int range = max - min + 1;

    // Initialize swaps array to 0
    int swaps[range];
    for (i = 0; i < range; i++)
        swaps[i] = 0;

    // Bubble sort algorithm
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swaps[arr[j] - min]++; // Increment the swap count for the swapped element
                count++;
            }
        }
    }

    // Print the swap counts for each element
    for (i = 0; i < n; i++) {
        printf("%d: %d of times %d is swapped\n", arr[i], swaps[arr[i] - min], arr[i]);
    }
    printf("total %d of swaps \n", count);
    printf("Array after Bubble sorting: ");

    for (i = 0; i < n; i++){
        printf("%d ",arr[i]);
    }
}

void selectionSort(int arr[], int n) {
    int i, j, temp, count = 0, min = arr[0], max = arr[0];

    // Find the minimum and maximum values in the array
    for (i = 1; i < n; i++) {
        if (arr[i] < min)
            min = arr[i];
        if (arr[i] > max)
            max = arr[i];
    }

    // Calculate the range of values to adjust indexing
    int range = max - min + 1;

    // Initialize swaps array to 0
    int swaps[range];
    for (i = 0; i < range; i++)
        swaps[i] = 0;

    // Selection sort algorithm
    for (i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
            swaps[arr[i] - min]++; // Increment the swap count for the swapped element
            count++;
        }
    }

    // Print the swap counts for each element
    for (i = 0; i < n; i++) {
        printf("%d: %d of times %d is swapped\n", arr[i], swaps[arr[i] - min], arr[i]);
    }
    printf("total %d of swaps \n", count);
    printf("Array after Selection sorting: ");

    for (i = 0; i < n; i++){
        printf("%d ",arr[i]);
    }
}

int main() {
    int arr[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int arr2[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Make copies of the original arrays
    int arr_copy[n];
    memcpy(arr_copy, arr, n * sizeof(int));

    int arr2_copy[n];
    memcpy(arr2_copy, arr2, n * sizeof(int));
    
    bubbleSort(arr, n);
    printf("\n");
    bubbleSort(arr2, n);

    selectionSort(arr_copy, n);
    printf("\n");
    selectionSort(arr2_copy, n);
    return 0;
}
