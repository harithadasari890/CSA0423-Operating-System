#include <stdio.h>

int main() {
    int indexBlock, n, blocks[20];

    printf("Enter index block number: ");
    scanf("%d", &indexBlock);

    printf("Enter number of blocks in file: ");
    scanf("%d", &n);

    printf("Enter the block numbers:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &blocks[i]);

    printf("\nIndexed Allocation:\n");
    printf("Index Block ? %d\n", indexBlock);

    for (int i = 0; i < n; i++)
        printf("Block %d ? Data Block %d\n", i, blocks[i]);

    return 0;
}

