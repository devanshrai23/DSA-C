#include <stdio.h>

int findLastOccurrence(int arr[], int n, int x) {
    if (n == 0) return -1;
    int lastIndex = findLastOccurrence(arr, n - 1, x);
    if (arr[n - 1] == x)
        return n - 1;

    return lastIndex;
}

int main() {
    int arr[] = {1, 3, 5, 3, 7, 3, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 3;

    int lastIndex = findLastOccurrence(arr, n, x);
    
    printf("Last occurrence of %d is at index: %d\n", x, lastIndex);
    return 0;
}
