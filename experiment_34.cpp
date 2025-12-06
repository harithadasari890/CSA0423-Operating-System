#include <stdio.h>

int main() {
    int start, length;

    printf("Enter starting block of file: ");
    scanf("%d", &start);

    printf("Enter number of blocks (size of file): ");
    scanf("%d", &length);

    printf("\nFile allocated sequentially:\n");
    for (int i = 0; i < length; i++)
        printf("Block %d allocated\n", start + i);

    return 0;
}

