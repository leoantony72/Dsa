#include<stdio.h>
#define MAX_TERM 10
struct Term {
    int row;
    int col;
    int value;
};

void inputMatrix(int matrix[10][10], int rows, int cols){
    int i,j;
    printf("enter the elements of matrix (%dx%d)",rows,cols);
    for(i=0;i<rows;i++){
        for(j=0;j<cols;j++){
            scanf("%d",&matrix[i][j]);
        }
    }
}

void convertToTuple(int matrix[10][10], int rows, int cols, struct Term tuple[]){
    int i,j;
    int k=1;
    tuple[0].row = rows;
    tuple[0].col = cols;
    tuple[0].value = 0;
    for(i=0;i<rows;i++){
        for(j=0;j<cols;j++){
            if(matrix[i][j]!=0){
                tuple[k].row = i;
                tuple[k].col = j;
                tuple[k].value = matrix[i][j];
                k++;
            }
        }
    }
    tuple[0].value = k-1;
}

void transpose(struct Term tuple[], struct Term transpose[]){
    int n = tuple[0].value;
    int i,j;
    int currentb = 1;
    transpose[0].row = tuple[0].row;
    transpose[0].col = tuple[0].col;
    transpose[0].value = n;

    if(n!=0){
       for(i=0;i<tuple[0].col;i++){
         for(j=1;j<=n;j++){
            if(tuple[j].col == i){
                transpose[currentb].row = tuple[j].col;
                transpose[currentb].col = tuple[j].row;
                transpose[currentb].value = tuple[j].value;
                currentb++;
            }
         }
       }
    }

}

void addMatrix(struct Term a[], struct Term b[], struct Term result[]){
    int i=1, j=1, k=1;
    if(a[0].row != b[0].row || a[0].col != b[0].col){
        printf("Matrices cannot be added!!");
        return;
    }
    result[0].row = a[0].row;
    result[0].col = a[0].col;
    while(i <= a[0].value && j <= b[0].value){
        if(a[i].row == b[j].row && a[i].col == b[j].col){
            result[k].row = a[i].row;
            result[k].col = a[i].col;
            result[k].value = a[i].value + b[j].value;
            i++;
            j++;
            k++;
        }else if(a[i].row < b[j].row || (a[i].row == b[j].row && a[i].col<b[j].col )){
            result[k] = a[i];
            i++;
            k++;
        }else{
            result[k]=b[j];
            j++;
            k++;
        }
    }

    while(i<=a[0].value){
        result[k]=a[i];
        i++;
        k++;
    }
    while(j<=b[0].value){
        result[k]=b[j];
        j++;
        k++;
    }
    result[0].value = k-1;
}

void display(struct Term a[]){
    int i;
    printf("Row\tColumn\tValue\n");
    for(i=0;i<=a[0].value;i++){
        printf("%d\t%d\t%d\n", a[i].row,a[i].col,a[i].value);
    }
}

void main(){
    int rows1,cols1, rows2,cols2;
    int matrix1[10][10], matrix2[10][10];
    struct Term tuple1[MAX_TERM], tuple2[MAX_TERM], transposed1[MAX_TERM], 
    transposed2[MAX_TERM], sum[MAX_TERM];

    printf("enter number of rows in the 1st matrix: ");
    scanf("%d",&rows1);
    printf("enter number of columns in the 1st matrix: ");
    scanf("%d",&cols1);
    inputMatrix(matrix1, rows1, cols1);
   

    printf("enter number of rows in the 2nd matrix: ");
    scanf("%d",&rows2);
    printf("enter number of columns in the 2nd matrix: ");
    scanf("%d",&cols2);
    inputMatrix(matrix2, rows2, cols2);

    convertToTuple(matrix1,rows1,cols1,tuple1);
    convertToTuple(matrix2,rows2,cols2,tuple2);

    transpose(tuple1,transposed1);
    transpose(tuple2,transposed2);

    display(transposed1);
    display(transposed2);

    addMatrix(tuple1, tuple2, sum);
    display(sum);

}