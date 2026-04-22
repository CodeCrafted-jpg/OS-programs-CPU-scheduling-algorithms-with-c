// 1. Write C program to simulate the FCFS CPU Scheduling
// algorithm. 

#include <stdio.h>

// FCFS Simulation: Assumes AT=0
int main() {
    int n, i, bt[20], wt[20], tat[20];
    float avg_wt = 0, avg_tat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("Enter Burst Times:\n");
    for(i = 0; i < n; i++) {
        printf("P[%d]: ", i + 1);
        scanf("%d", &bt[i]);
    }

    wt[0] = 0; 
    for(i = 1; i < n; i++)
        wt[i] = wt[i-1] + bt[i-1];

    printf("\nProcess\tBT\tWT\tTAT\n");
    for(i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
        avg_wt += wt[i];
        avg_tat += tat[i];
        printf("P[%d]\t%d\t%d\t%d\n", i+1, bt[i], wt[i], tat[i]);
    }
    printf("Avg WT: %.2f, Avg TAT: %.2f\n", avg_wt/n, avg_tat/n);
    return 0;
}
