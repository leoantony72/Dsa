#include<stdio.h>
int n_process,n_resource;
int alloc_m[100][100], max_m[100][100];
int available[100];
int need_m[100][100];

void calculate_need(){
    //need = max - allocation
    int i,j;
    for(i=0;i<n_process;i++){
        for(j=0;j<n_resource;j++){
            need_m[i][j] = max_m[i][j] - alloc_m[i][j];
        }    
    }
}

int is_safe(){
    //need < available -> add the allocation to avaialbel
    int i,j,k;
    int finish[100] = {0};
    int work[100];
    int safe_sequence[100];

    for (int i = 0; i < n_resource; i++) {
        work[i] = available[i];
    }
    int count =0;
    
    while(count < n_process){
        int found = 0;
        for(i=0;i<n_process;i++){
            if(!finish[i]){
                for(j=0;j<n_resource;j++){
                    if(need_m[i][j] > work[j]){
                        break;
                    }
                }

                if(j == n_resource){
                    //update the work = work+alloc[i][j]
                    for(k=0;k<n_process;k++){
                        work[k] += alloc_m[i][k];
                    }
                    safe_sequence[count++]=i;
                    found=1;
                    finish[i]=1;
                }

            }
        }
        if(!found){
            return 0;
        }

        printf("Safe sequence is: ");
        for (int i = 0; i < n_process; i++) {
            printf("P%d ", safe_sequence[i]);
        }
        printf("\n");
        return 1; // Safe state
        
    }
    
}

void print_state() {
    printf("Process Allocation Maximum Need\n");
    for (int i = 0; i < n_process; i++) {
        printf("P%d\t", i);
        for (int j = 0; j < n_resource; j++) {
            printf("%d ", alloc_m[i][j]);
        }
        printf("\t");
        for (int j = 0; j < n_resource; j++) {
            printf("%d ", max_m[i][j]);
        }
        printf("\t");
        for (int j = 0; j < n_resource; j++) {
            printf("%d ", need_m[i][j]);
        }
        printf("\n");
    }
}

void main(){
    int i,j;
    printf("enter no.of process:");
    scanf("%d",&n_process);

    printf("enter no.of resource:");
    scanf("%d",&n_resource);

    printf("enter the allocation matrix:");
    for(i=0;i<n_process;i++){
        for(j=0;j<n_resource;j++){
            scanf("%d",alloc_m[i][j]);
        }    
    }

    printf("enter the maximum matrix:");
    for(i=0;i<n_process;i++){
        for(j=0;j<n_resource;j++){
            scanf("%d",max_m[i][j]);
        }    
    }

    printf("enter the avaliable resources");
    for(i=0;i<n_resource;i++){
        scanf("%d",available[i]);
    }
    calculate_need();
    print_state();

    if (is_safe()) {
        printf("The system is in a safe state.\n");
    } else {
        printf("The system is not in a safe state.\n");
    }
}