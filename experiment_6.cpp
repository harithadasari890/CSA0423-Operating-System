#include <stdio.h>
int main() {
    int n, i, t = 0, done = 0;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    int burst[n], priority[n], remaining[n], wt[n], tat[n];
    float total_wt = 0, total_tat = 0;
    for(i = 0; i < n; i++) {
        printf("Enter burst time for P%d: ", i+1);
        scanf("%d", &burst[i]);
        remaining[i] = burst[i];
        printf("Enter priority for P%d (lower number = higher priority): ", i+1);
        scanf("%d", &priority[i]);
        wt[i] = tat[i] = 0;
    }
    while(done < n) {
        int min_priority = 9999, idx = -1;
        for(i = 0; i < n; i++) {
            if(remaining[i] > 0 && priority[i] < min_priority) {
                min_priority = priority[i];
                idx = i;
            }
        }
        if(idx != -1) {
            remaining[idx]--;  
            t++;               
            if(remaining[idx] == 0) {
                done++;
                tat[idx] = t;             
                wt[idx] = tat[idx] - burst[idx]; 
            }
        } else {
            t++; 
        }
    }
    printf("\nProcess\tBurst\tPriority\tWaiting\tTurnaround\n");
    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t\t%d\t%d\n", i+1, burst[i], priority[i], wt[i], tat[i]);
        total_wt += wt[i];
        total_tat += tat[i];
    }

    printf("\nAverage Waiting Time: %.2f\n", total_wt/n);
    printf("Average Turnaround Time: %.2f\n", total_tat/n);

    return 0;
}



