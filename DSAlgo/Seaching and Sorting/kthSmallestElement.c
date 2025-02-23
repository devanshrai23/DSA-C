#include <stdio.h>

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

        if (pivotIndex > k)
            return quickSelect(arr, left, pivotIndex - 1, k);
        else 
            return quickSelect(arr, pivotIndex + 1, right, k);
    }
    return -1;
}

int main() {
    int n, k;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the value of k: ");
    scanf("%d", &k);

    if (k > 0 && k <= n) {
        int kthSmallest = quickSelect(arr, 0, n - 1, k - 1);
        printf("The %dth smallest element is: %d\n", k, kthSmallest);
    } else {
        printf("Invalid input! k should be between 1 and %d.\n", n);
    }

    return 0;
}
