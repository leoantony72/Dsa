#include <stdio.h>

// Define the structure for a process
struct proc {
    int bt;  // Burst Time
    int wt;  // Waiting Time
    int tt;  // Turnaround Time
    int po;  // Process Order (ID)
};

int main() {
    int n, i, j, sum = 0;
    float avg_wt, avg_tat;  // Average waiting time and turnaround time

    // Input the number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    // Declare an array of processes
    struct proc p[n];
    struct proc temp; 
    // Input burst time for each process
    printf("Enter the burst time of each process:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &p[i].bt);
        p[i].po = i + 1;  // Assign process ID (1 to n)
    }

    // Sort processes by burst time (Shortest Job First)
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (p[i].bt > p[j].bt) {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    // Calculate waiting time for each process
    p[0].wt = 0;  // First process has no waiting time
    sum = p[0].wt;
    for (i = 1; i < n; i++) {
        p[i].wt = p[i - 1].wt + p[i - 1].bt;
        sum += p[i].wt;
    }

    // Calculate average waiting time
    avg_wt = (float)sum / n;

    // Calculate turnaround time for each process
    sum = 0;
    for (i = 0; i < n; i++) {
        p[i].tt = p[i].bt + p[i].wt;
        sum += p[i].tt;
    }

    // Calculate average turnaround time
    avg_tat = (float)sum / n;

    // Print the results in a tabular format
    printf("\nProcess\tBT\tWT\tTT\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\n", p[i].po, p[i].bt, p[i].wt, p[i].tt);
    }

    // Print average waiting and turnaround times
    printf("Average waiting time = %.2f\n", avg_wt);
    printf("Average turnaround time = %.2f\n", avg_tat);

    return 0;
}