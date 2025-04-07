#include<stdio.h>

void main(){
    int i,n;
    int b[100];
    int wt[100];
    int tat[100];
    int avgwt=0;
    int avgtat=0;
    printf("enter the no.of processes\n");
    scanf("%d",&n);

    for(i=0;i<n;i++){
        printf("enter the burst time of process");
        scanf("%d",&b[i]);
    }

    //wait time of first process is 0
    wt[0]=0;
    for(i=1;i<n;i++){
        wt[i]=b[i-1]+wt[i-1];
        avgwt+=wt[i];
    }
    
    for(i=0;i<n;i++){
        tat[i]=b[i]+wt[i];
        avgtat+=tat[i];
    }

    printf("Process\t\tBurst Time\t\t wait time\t\t turnaround time\n");
    for(i=0;i<n;i++){
        printf("%d\t\t%d\t\t\t%d\t\t\t%d\n",i,b[i],wt[i],tat[i]);
    }
    printf("Average wait time is %d\n",avgwt/n);
    printf("Average turnaround time is %d\n",avgtat/n);
}