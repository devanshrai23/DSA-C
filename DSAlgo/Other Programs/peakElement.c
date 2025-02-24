#include <stdio.h>

int findPeakElement(int arr[], int left, int right, int n) {
    int mid = left + (right - left) / 2;

    if ((mid == 0 || arr[mid - 1] < arr[mid]) && 
        (mid == n - 1 || arr[mid] > arr[mid + 1])) {
        return mid;
    }

    if (mid > 0 && arr[mid - 1] > arr[mid])
        return findPeakElement(arr, left, mid - 1, n);
    else
        return findPeakElement(arr, mid + 1, right, n);
}

int main() {
    int arr[] = {1, 3, 20, 4, 1, 0};
    int n = sizeof(arr) / sizeof(arr[0]);

    int peakIndex = findPeakElement(arr, 0, n - 1, n);

    printf("Peak element found at index: %d\n", peakIndex);
    
    return 0;
}
