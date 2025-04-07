#include<stdio.h>

void main(){
    int n,no,i,k,j=0;
    int a[100];
    int frame[100];
    int avail;
    int count=0; //for counting the page faults

    printf("enter the number of pages:");
    scanf("%d",&n);
    printf("enter the page number:");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("enter the number of frames:");
    scanf("%d",&no);

    for(i=0; i<no; i++) frame[i] = -1; // empty frame initialized with -1

    for(i=0;i<n;i++){
        printf("%d\t\t", a[i]);
        avail=0;
        for(k=0;k<no;k++){
            if(frame[k]==a[i]){
                //page hit
                avail=1;
                break;
            }
        }

        if(avail==0){
            //page fault
            frame[j] = a[i];
            j = (j+1)%no; //if j+1 reaches past the end of array, it resets it to 0. (circular queue)
            count++; //increment the page fault
    
            // print current frame state
             for(k=0; k<no; k++) {
                if(frame[k] != -1)
                    printf("%d\t", frame[k]);
                else
                    printf("-\t");
            }
        }
        printf("\n");
    }

    printf("page fault is %d", count);
}