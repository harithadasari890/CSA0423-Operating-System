#include <stdio.h>

int main() {
    int n, i;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int burst[n], wt = 0, tat;
    float total_wt = 0, total_tat = 0;

    for(i = 0; i < n; i++) {
        printf("Enter burst time for process P%d: ", i+1);
        scanf("%d", &burst[i]);
    }

    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");

    for(i = 0; i < n; i++) {
        tat = wt + burst[i];
        printf("P%d\t%d\t\t%d\t\t%d\n", i+1, burst[i], wt, tat);
        total_wt += wt;
        total_tat += tat;
        wt += burst[i];
    }

    printf("\nAverage Waiting Time: %.2f", total_wt/n);
    printf("\nAverage Turnaround Time: %.2f\n", total_tat/n);

    return 0;
}


