#include<stdio.h>
struct process{
    int p;
    int bt;
    int wt;
    int tat;
    int rt;
};
int main(){
    int n,i,j,done,time=0;
    int qt;
    int avgwt = 0, avgtat = 0;
    struct process p[100];
    struct process temp;

    printf("enter no.of process:");
    scanf("%d",&n);

    for(i=0;i<n;i++){
        printf("enter the burst time");
        scanf("%d",&p[i].bt);
        p[i].p = i;
        p[i].rt = p[i].bt;
    }

    printf("enter the qantum time:");
    scanf("%d",&qt);

    //calculate wt
    do {
        done = 1;
        for (i = 0; i < n; i++) {
            if (p[i].rt > 0) {
                if (p[i].rt > qt) {
                    time += qt;
                    p[i].rt -= qt;
                } else {
                    time += p[i].rt;
                    p[i].wt = time - p[i].bt;
                    p[i].rt = 0;
                }
                done = 0;
            }
        }
    } while (!done);
    


     // Calculate turnaround time
     float total_wt = 0, total_tat = 0;
     for (i = 0; i < n; i++) {
         p[i].tat = p[i].bt + p[i].wt;
         total_wt += p[i].wt;
         total_tat += p[i].tat;
     }
 
     // Print table
     printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
     for (i = 0; i < n; i++) {
         printf("%d\t%d\t\t%d\t\t%d\n", p[i].p, p[i].bt, p[i].wt, p[i].tat);
     }
 
     printf("\nAverage Waiting Time: %.2f\n", total_wt / n);
     printf("Average Turnaround Time: %.2f\n", total_tat / n);
}