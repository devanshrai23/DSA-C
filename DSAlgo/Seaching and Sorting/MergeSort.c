#include<stdio.h>
void merge(int arr[],int low,int mid,int high){
    int temp[high - low + 1];
    int left = low;
    int right = mid+1;
    int i=0;
    while(left <= mid && right <= high){
        if(arr[left] <= arr[right]){
            temp[i]=arr[left];
            left++;
            i++;
        }
        else{
            temp[i]=arr[right];
            right++;
            i++;
        }
    }
    while(left <= mid){
        temp[i]=arr[left];
        left++;
        i++;
    }
    while(right <= high){
        temp[i]=arr[right];
        right++;
        i++;
    }

    for(int i=low;i<=high;i++){
        arr[i]=temp[i-low];
    }
}

void mergesort(int arr[],int low, int high){
    if(low >= high){
        return;
    }
    int mid = (low + high)/2;
    mergesort(arr,low,mid);                         
    mergesort(arr,mid+1,high);                      
    merge(arr,low,mid,high);
}

void printArray(int arr[],int size){
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int main(){
    int arr[]={1,4,6,9,8,12,3,4,5,6};
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("Original Array : ");
    printArray(arr,n);

    mergesort(arr,0,n-1);

    printf("Sorted Array : ");
    printArray(arr,n);
    return 0;
}
