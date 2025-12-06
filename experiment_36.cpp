#include <stdio.h>

struct Block {
    int data;
    int next;
} blocks[50];

int main() {
    int start, n;

    printf("Enter starting block: ");
    scanf("%d", &start);

    printf("Enter number of blocks in file: ");
    scanf("%d", &n);

    printf("Enter block numbers in order:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &blocks[i].data);

    printf("\nLinked Allocation:\n");
    for (int i = 0; i < n - 1; i++) {
        blocks[i].next = blocks[i + 1].data;
        printf("Block %d ? Next %d\n", blocks[i].data, blocks[i].next);
    }

    blocks[n - 1].next = -1;
    printf("Block %d ? Next %d\n", blocks[n - 1].data, blocks[n - 1].next);

    return 0;
}

