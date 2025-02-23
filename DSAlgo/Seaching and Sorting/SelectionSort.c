#include <stdio.h>
#include <limits.h>

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = INT_MAX;
        int minIndex = -1;
        for (int j = i; j < n; j++) {
            if (arr[j] < min) {
                min = arr[j];
                minIndex = j;
            }
        }
        int temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}


int main() {
    int arr[] = {7, 4, 5, 9, 8, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original Array: ");
    printArray(arr, n);

    selectionSort(arr, n);

    printf("Sorted Array: ");
    printArray(arr, n);

    return 0;
}
