#include <stdio.h>

#define MAX_PROCESSES 5
#define MAX_RESOURCES 3

int need[MAX_PROCESSES][MAX_RESOURCES];
int maximum[MAX_PROCESSES][MAX_RESOURCES];
int allocation[MAX_PROCESSES][MAX_RESOURCES];
int available[MAX_RESOURCES];
int num_processes, num_resources;

void calculate_need() {
    for (int i = 0; i < num_processes; i++) {
        for (int j = 0; j < num_resources; j++) {
            need[i][j] = maximum[i][j] - allocation[i][j];
        }
    }
}

int is_safe() {
    int finish[MAX_PROCESSES] = {0};
    int safe_sequence[MAX_PROCESSES];
    int work[MAX_RESOURCES];

    for (int i = 0; i < num_resources; i++) {
        work[i] = available[i];
    }

    int count = 0;
    while (count < num_processes) {
        int found = 0;

        for (int p = 0; p < num_processes; p++) {
            if (!finish[p]) {
                int j;
                for (j = 0; j < num_resources; j++) {
                    if (need[p][j] > work[j]) {
                        break;
                    }
                }

                if (j == num_resources) {
                    for (int k = 0; k < num_resources; k++) {
                        work[k] += allocation[p][k];
                    }
                    safe_sequence[count++] = p;
                    finish[p] = 1;
                    found = 1;
                }
            }
        }

        if (!found) {
            return 0; // Not in a safe state
        }
    }

    printf("Safe sequence is: ");
    for (int i = 0; i < num_processes; i++) {
        printf("P%d ", safe_sequence[i]);
    }
    printf("\n");
    return 1; // Safe state
}

void print_state() {
    printf("Process Allocation Maximum Need\n");
    for (int i = 0; i < num_processes; i++) {
        printf("P%d\t", i);
        for (int j = 0; j < num_resources; j++) {
            printf("%d ", allocation[i][j]);
        }
        printf("\t");
        for (int j = 0; j < num_resources; j++) {
            printf("%d ", maximum[i][j]);
        }
        printf("\t");
        for (int j = 0; j < num_resources; j++) {
            printf("%d ", need[i][j]);
        }
        printf("\n");
    }
}

int main() {
    printf("Enter the number of processes: ");
    scanf("%d", &num_processes);
    printf("Enter the number of resources: ");
    scanf("%d", &num_resources);

    printf("Enter the allocation matrix:\n");
    for (int i = 0; i < num_processes; i++) {
        for (int j = 0; j < num_resources; j++) {
            scanf("%d", &allocation[i][j]);
        }
    }

    printf("Enter the maximum matrix:\n");
    for (int i = 0; i < num_processes; i++) {
        for (int j = 0; j < num_resources; j++) {
            scanf("%d", &maximum[i][j]);
        }
    }

    printf("Enter the available resources:\n");
    for (int i = 0; i < num_resources; i++) {
        scanf("%d", &available[i]);
    }

    calculate_need();
    print_state();

    if (is_safe()) {
        printf("The system is in a safe state.\n");
    } else {
        printf("The system is not in a safe state.\n");
    }

    return 0;
}
