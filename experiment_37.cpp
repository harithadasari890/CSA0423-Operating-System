#include <stdio.h>
#include <stdlib.h>   // Added for abs()

int main() {
    int n, head, req[20];

    printf("Enter number of disk requests: ");
    scanf("%d", &n);

    printf("Enter request queue: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &req[i]);

    printf("Enter initial head position: ");
    scanf("%d", &head);

    int total = 0;
    printf("\nMovement Order: %d", head);

    for (int i = 0; i < n; i++) {
        total += abs(req[i] - head);
        head = req[i];
        printf(" -> %d", head);
    }

    printf("\nTotal Head Movement = %d\n", total);

    return 0;
}


