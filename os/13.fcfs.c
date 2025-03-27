#include<stdio.h>

struct p {
    int id;
    int burstTime;
    int wt;
    int tt;
};

void main() {
    int n, s;
    int i = 0;
    float avgWt, avgTat;  // Use float for accurate division
    struct p process[100];

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter burst times:\n");
    for(i = 0; i < n; i++) {
        process[i].id = i;
        scanf("%d", &process[i].burstTime);
    }

 // Calculate Waiting Time
 process[0].wt = 0;  // First process has 0 waiting time
 for(i = 1; i < n; i++) {
     process[i].wt = process[i-1].wt + process[i-1].burstTime;
     avgWt += process[i].wt;  // Accumulate for avg
 }

 // Calculate Turnaround Time
 for(i = 0; i < n; i++) {
     process[i].tt = process[i].wt + process[i].burstTime;
     avgTat += process[i].tt;
 }

 avgWt /= n;
 avgTat /= n;


    printf("Avg waiting time: %f\n", avgWt);
    printf("Avg turnaround time: %f\n", avgTat);
}
