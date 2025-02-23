#include <stdio.h>

void bubbleSort(int arr[], int n) {
    int temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int minSum(int arr[], int n) {
    
    bubbleSort(arr, n);

    long long num1 = 0, num2 = 0;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0)
            num1 = num1 * 10 + arr[i];
        else
            num2 = num2 * 10 + arr[i];
    }
    return num1 + num2;
}

int main() {
    int n;
    printf("Enter the number of digits: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d digits (0-9): ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int result = minSum(arr, n);
    printf("The minimum possible sum is: %d\n", result);

    return 0;
}
