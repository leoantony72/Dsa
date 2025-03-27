#include <stdio.h>

struct proc {
    int bt;       // Burst Time
    int wt;       // Waiting Time
    int tt;       // Turnaround Time
    int po;       // Process ID
    int priority; // Priority (Lower value = Higher priority)
};

// Swap function
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Sort processes based on priority (Lower value = Higher priority)
void sortByPriority(struct proc p[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (p[i].priority > p[j].priority) {
                swap(&p[i].priority, &p[j].priority);
                swap(&p[i].bt, &p[j].bt);
                swap(&p[i].po, &p[j].po);
            }
        }
    }
}

int main() {
    int n, i, totalWT = 0, totalTT = 0;
    float avgWT, avgTT;

    printf("Enter the no. of processes: ");
    scanf("%d", &n);

    struct proc p[n];

    printf("Enter burst time and priority of each process\n");
    for (i = 0; i < n; i++) {
        printf("\nProcess %d\n", i + 1);
        printf("Burst Time = ");
        scanf("%d", &p[i].bt);
        printf("Priority = ");
        scanf("%d", &p[i].priority);
        p[i].po = i + 1; // Assign process number
    }

    // Step 1: Sort based on priority (Lower value = Higher priority)
    sortByPriority(p, n);

    // Step 2: Calculate Waiting Time (WT) & Turnaround Time (TT)
    p[0].wt = 0; // First process has 0 waiting time
    for (i = 1; i < n; i++) {
        p[i].wt = p[i - 1].wt + p[i - 1].bt; // Previous WT + Previous BT
        totalWT += p[i].wt;
    }

    // Step 3: Calculate Turnaround Time (TT)
    for (i = 0; i < n; i++) {
        p[i].tt = p[i].wt + p[i].bt;
        totalTT += p[i].tt;
    }

    // Step 4: Calculate Averages
    avgWT = (float)totalWT / n;
    avgTT = (float)totalTT / n;

    // Step 5: Print the Table
    printf("\nProcess\tBT\tPriority\tWT\tTT\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t\t%d\t%d\n", p[i].po, p[i].bt, p[i].priority, p[i].wt, p[i].tt);
    }

    printf("\nAverage Waiting Time = %.2f ms\n", avgWT);
    printf("Average Turnaround Time = %.2f ms\n", avgTT);

    return 0;
}
