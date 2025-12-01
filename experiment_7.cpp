#include <stdio.h>
int main() {
    int n, i, j, temp;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int burst[n], process[n], wt[n], tat[n];
    float total_wt = 0, total_tat = 0;
    for(i = 0; i < n; i++) {
        printf("Enter burst time for process P%d: ", i+1);
        scanf("%d", &burst[i]);
        process[i] = i+1;  
    }
    for(i = 0; i < n-1; i++) {
        for(j = i+1; j < n; j++) {
            if(burst[i] > burst[j]) {
                temp = burst[i];
                burst[i] = burst[j];
                burst[j] = temp;
                temp = process[i];
                process[i] = process[j];
                process[j] = temp;
            }
        }
    }
    wt[0] = 0;
    tat[0] = burst[0];

    for(i = 1; i < n; i++) {
        wt[i] = wt[i-1] + burst[i-1];
        tat[i] = wt[i] + burst[i];
    }
    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\n", process[i], burst[i], wt[i], tat[i]);
        total_wt += wt[i];
        total_tat += tat[i];
    }

    printf("\nAverage Waiting Time: %.2f", total_wt/n);
    printf("\nAverage Turnaround Time: %.2f\n", total_tat/n);

    return 0;
}

