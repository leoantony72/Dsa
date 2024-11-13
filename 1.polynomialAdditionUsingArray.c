#include<stdio.h>
struct Term{
    int coeff;
    int expo;
};

void inputPolynomial(struct Term poly[],int n){
    int i;
    for(i=0;i<n;i++){
        printf("Enter the coefficient and exponent:");
        scanf("%d%d",&poly[i].coeff,&poly[i].expo);
    }
}
int addPolynomial(struct Term poly1[],int n1,struct Term poly2[],int n2,struct Term result[]){
    int i=0,j=0,k=0;
    while(i<n1 && j<n2){

        if(poly1[i].expo == poly2[j].expo){
            result[k].expo= poly1[i].expo;
            result[k].coeff= poly1[i].coeff + poly2[j].coeff;
            i++;
            j++;
            k++;
        }else if(poly1[i].expo > poly2[j].expo){
            result[k].expo = poly1[i].expo;
            result[k].coeff = poly1[i].coeff;
            k++;
            i++;
        }else if(poly1[i].expo < poly1[j].expo){
            result[k].expo = poly2[j].expo;
            result[k].coeff = poly2[j].coeff;
            k++;
            j++;
        }
    }

    while(i<n1){
        result[k] = poly1[i];
        i++;
        k++;
    }
    while(j<n2){
        result[k] = poly2[j];
        j++;
        k++;
    }

    return k;
}

void main(){
    struct Term poly1[100],poly2[100],result[100];
    int n1,n2,n3,i;
    printf("enter the number of terms in the first polynomial:");
    scanf("%d",&n1);
    inputPolynomial(poly1,n1);
    printf("enter the number of terms in the second polynomial:");
    scanf("%d",&n2);
    inputPolynomial(poly2,n2);

    n3=addPolynomial(poly1,n1,poly2,n2,result);

    printf("<---Output--->\n");
    for(i=0;i<n3;i++){
        printf("Coeff: %d | expo: %d \n",result[i].coeff,result[i].expo);
    }

}