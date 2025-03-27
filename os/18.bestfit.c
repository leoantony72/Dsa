#include <stdio.h>

struct process {
    int size;
    int block;
};

int main() {
    int np, nb, i, j, temp, low = 10000, bflag[20], fflag[20];

    printf("Enter the no. of processes: ");
    scanf("%d", &np);

    printf("\nEnter the no. of memory blocks: ");
    scanf("%d", &nb);

    int b[nb];
    struct process p[np];

    printf("\nEnter the size of each process:\n");
    for (i = 0; i < np; i++) {
        scanf("%d", &p[i].size);
        p[i].block = -1;
    }

    printf("\nEnter the size of each block:\n");
    for (i = 0; i < nb; i++) {
        scanf("%d", &b[i]);
    }

    for (i = 0; i < np; i++) {
        for (j = 0; j < nb; j++) {
            if (bflag[j] != 1) {
                temp = b[j] - p[i].size;
                if (temp >= 0) {
                    if (low > temp) {
                        fflag[i] = j;
                        low = temp;
                    }
                }
            }
        }
        bflag[fflag[i]] = 1;
        low = 10000;
    }

    printf("\nFile No\tFile Size\tBlock No\tBlock Size");
    for (i = 0; i < np; i++) {
        printf("\n\n%d\t\t%d\t\t%d\t\t%d", i, p[i].size, fflag[i], b[fflag[i]]);
    }

    return 0;
}
