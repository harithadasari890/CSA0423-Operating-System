#include <stdio.h>
#include <stdlib.h>

int main() {
    int req[20], n, head, diskSize, direction;

    printf("Enter number of requests: ");
    scanf("%d", &n);

    printf("Enter request queue: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &req[i]);

    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("Enter total disk size: ");
    scanf("%d", &diskSize);

    printf("Enter direction (0 = left, 1 = right): ");
    scanf("%d", &direction);

    req[n] = 0;
    req[n + 1] = diskSize - 1;
    n += 2;

    // Sort requests
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (req[i] > req[j]) {
                int temp = req[i];
                req[i] = req[j];
                req[j] = temp;
            }

    int index;
    for (int i = 0; i < n; i++)
        if (req[i] >= head) {
            index = i;
            break;
        }

    int total = 0;
    int current = head;

    printf("\nMovement Order: %d", head);

    if (direction == 1) { // Right
        for (int i = index; i < n; i++) {
            total += abs(req[i] - current);
            current = req[i];
            printf(" -> %d", current);
        }
        for (int i = index - 1; i >= 0; i--) {
            total += abs(req[i] - current);
            current = req[i];
            printf(" -> %d", current);
        }
    } else { // Left
        for (int i = index - 1; i >= 0; i--) {
            total += abs(req[i] - current);
            current = req[i];
            printf(" -> %d", current);
        }
        for (int i = index; i < n; i++) {
            total += abs(req[i] - current);
            current = req[i];
            printf(" -> %d", current);
        }
    }

    printf("\nTotal Head Movement = %d\n", total);

    return 0;
}


