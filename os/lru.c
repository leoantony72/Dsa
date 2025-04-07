#include<stdio.h>


void main(){
    int i,j,k,n,no;
    int a[100],frame[100],time[100];
    int counter=0;
    int count =0;
    int avail;

    printf("enter the number of pages:");
    scanf("%d",&n);

    printf("enter the pages:");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    printf("enter the number of frames:");
    scanf("%d",&no);

    for(i=0;i<no;i++){
        frame[i] = -1;
        time[i] = -1;
    }

    printf("Ref string\t\tPage frames\n");
    for(i=0;i<n;i++){
        printf("%d\t\t",a[i]);
        avail=0;
        for(j=0;j<no;j++){
            if(frame[j]==a[i]){
                //page hit
                avail=1;
                break;
            }
        }

        if(avail==0){
            //remove the least used element
            int lru=0;
            if(frame[0]==-1){
                lru =0;
            }else{
                //find the least time 
                for(k=1;k<no;k++){
                    if(time[k] < time[lru]){
                        lru = k;
                    }
                }
            }

            frame[lru]=a[i];
            time[lru]=++counter;
            count++;
        }
        for(k=0;k<no;k++){
            if(frame[k]==-1){
                printf("- ");
            }else{
                printf("%d ", frame[k]);
            }
        }
        printf("\n");
    }

    
    printf("\nTotal Page Faults = %d\n", count);
}