#include<stdio.h>
#include<stdbool.h>
int main(){
    int arr[]={5,0,2,0,0,4,1,3,0};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Original Array : ");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }

    for(int i=0;i<n-1;i++){
        bool flag = true;
        for(int j=0;j<n-1-i;j++){
            if(arr[j]==0){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                flag = false;
            }
        }
        if(flag==true){
            break;
        }    
    }

    printf("\nUpdated Array : ");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}
