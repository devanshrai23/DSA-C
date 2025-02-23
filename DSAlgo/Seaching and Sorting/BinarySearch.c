#include<stdio.h>

int binary_search(int arr[],int n,int data){
    int l=0,r=n-1,mid;
    while(l<=r){
        mid = (l+r)/2;
        if(arr[mid]==data){
            return mid;
        }
        else if(arr[mid]>data){
            r=mid-1;
        }
        else
            l=mid+1;
    }
    return -1;
}

int main(){
    int t;
    printf("Enter target element : ");
    scanf("%d",&t);
    int arr[]={5,9,17,23,35,45,59,63,71,89};
    int size= sizeof(arr)/sizeof(arr[0]);
    int result = binary_search(arr, size, t);
    if (result != -1) {
        printf("Target element is at index: %d\n", result);
    } 
    else {
        printf("Target element not found in the array\n");
    }
    return 0;
}

//Recursive Code
#include <stdio.h>


int binary_search_recursive(int arr[], int l, int r, int data) {
    if (l > r) {
        return -1;
    }
    int mid = (l + r) / 2;

    if (arr[mid] == data) return mid;
    else if (arr[mid] > data) return binary_search_recursive(arr, l, mid - 1, data); 
    else return binary_search_recursive(arr, mid + 1, r, data);
}

int main() {
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15};
    int n = sizeof(arr) / sizeof(arr[0]);
    int data = 7;

    int index = binary_search_recursive(arr, 0, n - 1, data);
    if (index != -1) {
        printf("Element found at index %d\n", index);
    } else {
        printf("Element not found\n");
    }

    return 0;
}
