#include <stdio.h>
#include <stdbool.h>

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {        
        bool flag = true;
        for (int j = 0; j < n - i - 1; j++) {  
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                flag = false;  
            }
        }
        if (flag) {
            break;
        }
    }
}

void printArray(int arr[],int n){
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {6, 10, 9, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    printArray(arr,n);
    bubbleSort(arr, n);
    printArray(arr,n);

    return 0;
}
