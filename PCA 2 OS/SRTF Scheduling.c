// 4. Write C program to simulate the SRTF Scheduling algorithm. 
#include <stdio.h>

#define MAX 10

int main() {
    int n;
    int pid[MAX], at[MAX], bt[MAX], rt[MAX];
    int ct[MAX], tat[MAX], wt[MAX];
    int completed = 0, time = 0, minRT, shortest = -1;
    float totalTAT = 0, totalWT = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        pid[i] = i + 1;
        printf("Enter Arrival Time and Burst Time for Process P%d: ", i + 1);
        scanf("%d %d", &at[i], &bt[i]);
        rt[i] = bt[i];   // remaining time = burst time initially
    }

    printf("\nGantt Chart:\n|");

    while (completed != n) {
        // Find process with minimum remaining time among arrived processes
        minRT = 99999;
        shortest = -1;

        for (int i = 0; i < n; i++) {
            if (at[i] <= time && rt[i] > 0 && rt[i] < minRT) {
                minRT = rt[i];
                shortest = i;
            }
        }

        if (shortest == -1) {
            // No process available, CPU idle
            printf(" IDLE |");
            time++;
            continue;
        }

        // Execute shortest process for 1 unit
        printf(" P%d |", pid[shortest]);
        rt[shortest]--;
        time++;

        // If process is completed
        if (rt[shortest] == 0) {
            completed++;
            ct[shortest] = time;
            tat[shortest] = ct[shortest] - at[shortest];
            wt[shortest]  = tat[shortest] - bt[shortest];
            totalTAT += tat[shortest];
            totalWT  += wt[shortest];
        }
    }

    printf("\n\n");

    // Print results
    printf("%-10s %-15s %-15s %-20s %-20s %-15s\n",
           "Process", "Arrival Time", "Burst Time",
           "Completion Time", "Turnaround Time", "Waiting Time");
    printf("-----------------------------------------------------------------------"
           "-------------------\n");

    for (int i = 0; i < n; i++) {
        printf("%-10d %-15d %-15d %-20d %-20d %-15d\n",
               pid[i], at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    printf("\nAverage Turnaround Time : %.2f\n", totalTAT / n);
    printf("Average Waiting Time    : %.2f\n",  totalWT  / n);

    return 0;
}