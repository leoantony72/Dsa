#include<stdio.h>
void insertionSort(int arr[],int n){
    int i,j,key;
    for(i=1;i<n;i++){
        key=arr[i];
        j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}

void main(){
    int arr[100],length,i;
    printf("Enter length:");
    scanf("%d",&length);

    for(i=0;i<length;i++){
        scanf("%d",&arr[i]);
    }

    insertionSort(arr,length);

    printf("<---Output--->\n");
    for(i=0;i<length;i++){
        printf("%d \n",arr[i]);
    }
}