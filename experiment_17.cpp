 #include <stdio.h>

int main() {
    int n, r;
    printf("Enter no. of processes: ");
    scanf("%d", &n);

    printf("Enter no. of resources: ");
    scanf("%d", &r);

    int alloc[n][r], max[n][r], avail[r], need[n][r];

    printf("Enter Allocation Matrix:\n");
    for (int i=0;i<n;i++)
        for (int j=0;j<r;j++)
            scanf("%d",&alloc[i][j]);

    printf("Enter Max Matrix:\n");
    for (int i=0;i<n;i++)
        for (int j=0;j<r;j++)
            scanf("%d",&max[i][j]);

    printf("Enter Available resources:\n");
    for (int i=0;i<r;i++) scanf("%d",&avail[i]);

    for (int i=0;i<n;i++)
        for (int j=0;j<r;j++)
            need[i][j] = max[i][j] - alloc[i][j];

    int finish[n], safe[n], count = 0;
    for (int i=0;i<n;i++) finish[i] = 0;

    while (count < n) {
        int flag = 0;
        for (int i=0;i<n;i++) {
            if (!finish[i]) {
                int j;
                for (j=0;j<r;j++)
                    if (need[i][j] > avail[j])
                        break;

                if (j == r) {
                    for (int k=0;k<r;k++)
                        avail[k] += alloc[i][k];

                    safe[count++] = i;
                    finish[i] = 1;
                    flag = 1;
                }
            }
        }
        if (!flag) break;
    }

    if (count == n) {
        printf("\nSafe Sequence: ");
        for (int i=0;i<n;i++)
            printf("P%d ", safe[i]);
    } else
        printf("System is in Deadlock!");

    return 0;
}


