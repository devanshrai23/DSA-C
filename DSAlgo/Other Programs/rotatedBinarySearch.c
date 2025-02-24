#include <stdio.h>

int searchInRotatedArray(int arr[], int left, int right, int x) {
    if (left > right) return -1;
    int mid = left + (right - left) / 2;

    if (arr[mid] == x) return mid;
    if (arr[left] <= arr[mid]) {
        if (arr[left] <= x && x < arr[mid])
            return searchInRotatedArray(arr, left, mid - 1, x);
        else
            return searchInRotatedArray(arr, mid + 1, right, x);
    }

    if (arr[mid] <= x && x <= arr[right])
        return searchInRotatedArray(arr, mid + 1, right, x);
    else
        return searchInRotatedArray(arr, left, mid - 1, x);
}

int main() {
    int arr[] = {10, 15, 20, 0, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 5;

    int index = searchInRotatedArray(arr, 0, n - 1, x);

    if (index != -1)
        printf("Element %d found at index: %d\n", x, index);
    else
        printf("Element %d not found in the array.\n", x);

    return 0;
}
