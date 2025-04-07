#include<stdio.h>

struct process{
    int p;
    int bt;
    int wt;
    int tat;
};
void main(){
    int i,j,n;
    int avgwt;
    int avgtat;

    struct process p[100]; 
    struct process temp;

    printf("enter no.of process:");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("enter the burst time");
        scanf("%d",&p[i].bt);
        p[i].p = i;
    }

    //sort the burst time in the process struct;
    for(i=0;i<n-1;i++){
        for(j=i+1;j<n;j++){
            if(p[i].bt > p[j].bt){
                //swap p[i] & p[j]
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    //calculate wt
    p[0].wt = 0;
    for(i=1;i<n;i++){
        p[i].wt = p[i-1].wt + p[i-1].bt;
        avgwt+=p[i].wt;

    }

    //calculate tat
    for(i=0;i<n;i++){
        p[i].tat = p[i].wt + p[i].bt;
        avgtat+=p[i].tat;
    }


    for(i=0;i<n;i++){
        printf("Process\t\tBurst Time\t\twait time\t\tturn around time\n");
        printf("%d\t\t%d\t\t\t%d\t\t\t%d\n",p[i].p,p[i].bt,p[i].wt,p[i].tat);
    }

    printf("avg wait time:%d",avgwt/n);
    printf("avg turnaround time:%d",avgtat/n);
    

}