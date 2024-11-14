#include<stdio.h>
#include<stdlib.h>
struct term{
    int r;
    int c;
    int value;
};
void toTuple(int m[20][20],int r, int c,struct term tuple[100]){
    int i,j;  
    int k =1;
    tuple[0].r=r;
    tuple[0].c=c;
    tuple[0].value=0;
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            if(m[i][j]!=0){
                tuple[k].r=i;
                tuple[k].c=j;
                tuple[k].value=m[i][j];
                k++;
            }
        }
    }
    tuple[0].value=k-1;

}

void displayTuple(struct term tuple[100]){
    int i;
    for(i=0;i<=tuple[0].value;i++){
        printf("row :%d | column:%d | value:%d \n",tuple[i].r,tuple[i].c,tuple[i].value);
    }
}

void transpose(struct term a[100], struct term b[100]){
    int i,j,n,k=1;
    b[0].r= a[0].c;
    b[0].c=a[0].r;
    b[0].value=a[0].value;
    n = a[0].value;
    for(i=0;i<a[0].c;i++){
        for(j=1;j<=n;j++){
            if(a[j].c==i){
                b[k].r=a[j].c;
                b[k].c=a[j].r;
                b[k].value=a[j].value;
                k++;
            }
        }
    }
}

void main(){
    int r,c;
    int i,j;
    int matrix[20][20];
    struct term tuple1[100];
    struct term transposed1[100];
    printf("enter no.of rows and columns:");
    scanf("%d",&r);
    scanf("%d",&c);

    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            scanf("%d",&matrix[i][j]);
        }
    }

    toTuple(matrix,r,c,tuple1);
    printf("----TUPLE FORM-----\n");
    displayTuple(tuple1);

    transpose(tuple1,transposed1);
    printf("----TRANSPOSED TUPLE FORM-----\n");

    displayTuple(transposed1);
}
