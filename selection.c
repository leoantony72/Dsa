#include<stdio.h>

void SelectionSort(int arr[],int n){
    int i,j,min,temp;
    for(i=0;i<n-1;i++){
        min=i;
        for(j=i+1;j<n;j++){
            if(arr[j]<arr[min]){
                min=j;
            }
        }
        temp=arr[i];
        arr[i]=arr[min];
        arr[min]=temp;
    }
}



int main(){
    int arr[100],length,i;

    scanf("%d",&length);

    for(i=0;i<length;i++){
        scanf("%d",&arr[i]);
    }

    SelectionSort(arr,length);

    printf("<---Output--->\n");
    for(i=0;i<length;i++){
        printf("%d \n",arr[i]);
    }
}