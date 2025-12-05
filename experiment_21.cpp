#include <stdio.h>
int main() {
    int blockSize[10], processSize[10], b, p, alloc[10];  
    printf("Enter number of blocks: ");
    scanf("%d", &b);
    printf("Enter block sizes:\n");
    for (int i = 0; i < b; i++)
        scanf("%d", &blockSize[i]);
    printf("Enter number of processes: ");
    scanf("%d", &p);
    printf("Enter process sizes:\n");
    for (int i = 0; i < p; i++)
        scanf("%d", &processSize[i]);

    for (int i = 0; i < p; i++) {
        int worst = -1;
        for (int j = 0; j < b; j++) {
            if (blockSize[j] >= processSize[i]) {
                if (worst == -1 || blockSize[j] > blockSize[worst])
                    worst = j;
            }
        }
        alloc[i] = worst;
        if (worst != -1)
            blockSize[worst] -= processSize[i];
    }
    printf("\nProcess  Size  Block\n");
    for (int i = 0; i < p; i++) {
        printf("%d\t%d\t", i+1, processSize[i]);
        if (alloc[i] != -1)
            printf("%d\n", alloc[i]+1);
        else
            printf("Not Allocated\n");
    }
    return 0;
}

