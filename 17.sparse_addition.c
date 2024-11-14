//sum of sparse matrix in tuple form !!
#include<stdio.h>
struct term {
    int row;
    int col;
    int value;
};


void inputMatrix(int row, int col, int matrix[20][20]){
    int i,j;
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            scanf("%d",&matrix[i][j]);
        }
    }
}

void toTuple(int matrix[20][20], struct term tuple[100], int r, int c){
    int i,j;
    int k=1;

    tuple[0].row = r;
    tuple[0].col = c;
    for(i=0;i<r;i++){
        for(j=0;j<r;j++){
            if(matrix[i][j]!=0){
                tuple[k].row=i;
                tuple[k].col=j;
                tuple[k].value=matrix[i][j];
                k++;
            }
        }
    }
    tuple[0].value=k-1;
}

void addition(struct term a[100],struct term b[100], struct term r[100]){
    int i=1,j=1,k=1;
    r[0].row = a[0].row;
    r[0].col = a[0].col;

    while(i<=a[0].value&&j<=b[0].value){
        if(a[i].row == b[j].row && a[i].col == b[j].col){
            r[k].row = a[i].row;
            r[k].col = a[i].col;
            r[k].value = a[i].value + b[j].value;
            k++;
            i++;
            j++;
        }else if(a[i].row < b[j].row || (a[i].row==b[j].row && a[i].col<b[j].col) ){
            r[k]=a[i];
            i++;
            k++;
        }else{
            r[k]=b[j];
            j++;
            k++;
        }
    }

    while(i<=a[0].value){
        r[k]=a[i];
        i++;
        k++;
    }
    while(j<=b[0].value){
        r[k]=b[j];
        j++;
        k++;
    }
    r[0].value=k-1;
}

void displayTuple(struct term tuple[100]){
    int i;
    for(i=0;i<=tuple[0].value;i++){
        printf("row :%d | column:%d | value:%d \n",tuple[i].row,tuple[i].col,tuple[i].value);
    }
}

void main(){
    int row,col;
    int row2,col2;
    int matrix1[20][20];
    int matrix2[20][20];

    struct term tuple1[100]; 
    struct term tuple2[100]; 
    struct term result[100]; 
    printf("enter the no.of rows and coloums for 1st matrix:");
    scanf("%d",&row);
    scanf("%d",&col);
    inputMatrix(row,col,matrix1);
    printf("enter the no.of rows and coloums for 2nd matrix:");
    scanf("%d",&row2);
    scanf("%d",&col2);
    inputMatrix(row2,col2,matrix2);

    toTuple(matrix1,tuple1,row,col);
    toTuple(matrix2,tuple2,row2,col2);

    printf("----TUPLE FORM 1-----\n");
    displayTuple(tuple1);
    printf("----TUPLE FORM 2-----\n");
    displayTuple(tuple2);

    printf("----ADDITION----\n");
    addition(tuple1,tuple2,result);
    displayTuple(result);
}