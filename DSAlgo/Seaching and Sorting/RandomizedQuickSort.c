#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int start = low;
    int end = high;
    while (start < end) {
        while (arr[start] <= pivot && start <= high - 1) {
            start++;
        }
        while (arr[end] > pivot && end >= low + 1) {
            end--;
        }
        if (start < end) {
            swap(&arr[start], &arr[end]);
        }
    }
    swap(&arr[low], &arr[end]);
    return end;
}

int random_partition(int arr[], int low, int high) {
    int random_index = low + rand() % (high - low + 1);
    swap(&arr[low], &arr[random_index]);
    return partition(arr, low, high);
}

void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int pIndex = random_partition(arr, low, high);
        quicksort(arr, low, pIndex - 1);
        quicksort(arr, pIndex + 1, high);
    }
}

void printarray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {7, 6, 10, 5, 9, 2, 1, 15, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    srand(time(0));

    printf("Original Array: ");
    printarray(arr, n);

    quicksort(arr, 0, n - 1);

    printf("Sorted Array: ");
    printarray(arr, n);

    return 0;
}
