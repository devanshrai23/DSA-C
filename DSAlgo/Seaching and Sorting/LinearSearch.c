#include<stdio.h>
#include<stdbool.h>
void main(){
    int t;
    printf("Enter a target element : ");
    scanf("%d",&t);
    int arr[]={15,5,2,5,65,42,12,3};
    int n=sizeof(arr)/sizeof(arr[0]);
    bool flag=false;
    for(int i=0;i<n;i++){
        if(arr[i]==t){
            printf("%d is present at index : %d",t,i);
            flag=true;
            break;                 
        }
    }
    if(flag==false){
        printf("Element not found");
    }
}