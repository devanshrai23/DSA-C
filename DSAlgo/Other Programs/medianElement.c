#include <stdio.h>
#include <stdlib.h>

int partition(int arr[], int left, int right) {
    int pivot = arr[right]; 
    int i = left - 1;

    for (int j = left; j < right; j++) {
        if (arr[j] <= pivot) { 
            i++;
            int temp = arr[i]; 
            arr[i] = arr[j]; 
            arr[j] = temp;
        }
    }

    int temp = arr[i + 1]; 
    arr[i + 1] = arr[right]; 
    arr[right] = temp;

    return i + 1;
}

int quickSelect(int arr[], int left, int right, int k) {
    if (left <= right) {
        int pivotIndex = partition(arr, left, right);

        if (pivotIndex == k)
            return arr[pivotIndex];
        else if (pivotIndex > k)
            return quickSelect(arr, left, pivotIndex - 1, k);
        else
            return quickSelect(arr, pivotIndex + 1, right, k);
    }
    return -1;
}

int findMedian(int arr[], int n) {
    if (n % 2 == 1) 
        return quickSelect(arr, 0, n - 1, n / 2);
    else
        return quickSelect(arr, 0, n - 1, (n / 2) - 1);
}

int main() {
    int arr[] = {7, 1, 3, 5, 2, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Median: %d\n", findMedian(arr, n));
    return 0;
}
