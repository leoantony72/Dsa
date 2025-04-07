#include<stdio.h>
struct process{
    int p;
    int bt;
    int wt;
    int tat;
    int priority;
};
void main(){
    int n,i,j;
    int avgwt = 0, avgtat = 0;
    struct process p[100];
    struct process temp;

    printf("enter no.of process:");
    scanf("%d",&n);

    for(i=0;i<n;i++){
        printf("enter the burst time");
        scanf("%d",&p[i].bt);

        printf("enter the priority");
        scanf("%d",&p[i].priority);
        p[i].p = i;
    }

    //sort by priority
    for(i=0;i<n-1;i++){
        for(j=i+1;j<n;j++){
            if(p[i].priority > p[j].priority){
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    //calculate wt
    p[0].wt = 0;
    for(i=1;i<n;i++){
        p[i].wt = p[i-1].bt  + p[i-1].wt;
        avgwt+=p[i].wt;
    }

    for(i=0;i<n;i++){
        p[i].tat = p[i].wt + p[i].bt;
        avgtat+=p[i].tat;
    }

    for(i=0;i<n;i++){
        printf("Process\t\tPriority\t\tBurst Time\t\twait time\t\tturn around time\n");
        printf("%d\t\t%d\t\t\t%d\t\t\t%d\t\t\t%d\n",p[i].p,p[i].priority,p[i].bt,p[i].wt,p[i].tat);
    }

    printf("avg wait time:%d",avgwt/n);
    printf("avg turnaround time:%d",avgtat/n);
}