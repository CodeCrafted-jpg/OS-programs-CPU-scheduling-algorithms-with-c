// 5. Write C program to simulate the Priority CPU Scheduling
// algorithm.
#include <stdio.h>

#define MAX 10

int main() {
    int n;
    int pid[MAX], at[MAX], bt[MAX], pri[MAX];
    int ct[MAX], tat[MAX], wt[MAX];
    int completed = 0, time = 0;
    int selected, found;
    float totalTAT = 0, totalWT = 0;
    int done[MAX] = {0};  // tracks if process is completed

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("\n");
    for (int i = 0; i < n; i++) {
        pid[i] = i + 1;
        printf("Enter Arrival Time, Burst Time, Priority for P%d: ", i + 1);
        scanf("%d %d %d", &at[i], &bt[i], &pri[i]);
    }

    printf("\nGantt Chart:\n|");

    while (completed != n) {
        // Find highest priority process that has arrived and not completed
        // Lower priority number = Higher priority
        selected = -1;
        found = 0;

        for (int i = 0; i < n; i++) {
            if (at[i] <= time && !done[i]) {
                if (!found || pri[i] < pri[selected]) {
                    selected = i;
                    found = 1;
                }
            }
        }

        if (selected == -1) {
            // No process available, CPU is idle
            printf(" IDLE |");
            time++;
            continue;
        }

        // Execute selected process completely (non-preemptive)
        for (int t = 0; t < bt[selected]; t++) {
            printf(" P%d |", pid[selected]);
            time++;
        }

        // Record completion details
        ct[selected]  = time;
        tat[selected] = ct[selected] - at[selected];
        wt[selected]  = tat[selected] - bt[selected];
        totalTAT     += tat[selected];
        totalWT      += wt[selected];
        done[selected] = 1;
        completed++;
    }

    printf("\n\n");

    // Print result table
    printf("%-10s %-15s %-15s %-12s %-20s %-20s %-15s\n",
           "Process", "Arrival Time", "Burst Time", "Priority",
           "Completion Time", "Turnaround Time", "Waiting Time");
    printf("-------------------------------------------------------------------------------------"
           "----------\n");

    for (int i = 0; i < n; i++) {
        printf("%-10d %-15d %-15d %-12d %-20d %-20d %-15d\n",
               pid[i], at[i], bt[i], pri[i], ct[i], tat[i], wt[i]);
    }

    printf("\nAverage Turnaround Time : %.2f\n", totalTAT / n);
    printf("Average Waiting Time    : %.2f\n",  totalWT  / n);

    return 0;
}