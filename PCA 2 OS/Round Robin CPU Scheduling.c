// 3. Write C program to simulate the Round Robin CPU Scheduling
// algorithm. 
#include <stdio.h>

int main() {
    int n, i, temp, quantum, count = 0, time = 0;
    int wait_time = 0, turnaround_time = 0;
    int at[10], bt[10], rt[10]; // Arrival, Burst, and Remaining time

    printf("Enter Total Number of Processes: ");
    scanf("%d", &n);

    int remain = n; // To track how many processes are finished

    for (i = 0; i < n; i++) {
        printf("Enter Arrival Time and Burst Time for Process P%d: ", i + 1);
        scanf("%d %d", &at[i], &bt[i]);
        rt[i] = bt[i]; // Initially, remaining time is equal to burst time
    }

    printf("\nEnter Time Quantum: ");
    scanf("%d", &quantum);

    printf("\nProcessID\tBurst Time\tTurnaround Time\tWaiting Time\n");

    // Logic for Round Robin
    for (time = 0, i = 0; remain != 0;) {
        if (rt[i] <= quantum && rt[i] > 0) {
            time += rt[i];
            rt[i] = 0;
            count = 1;
        } else if (rt[i] > 0) {
            rt[i] -= quantum;
            time += quantum;
        }

        if (rt[i] == 0 && count == 1) {
            remain--; // One process finished
            printf("P%d\t\t%d\t\t%d\t\t%d\n", i + 1, bt[i], time - at[i], time - at[i] - bt[i]);
            wait_time += time - at[i] - bt[i];
            turnaround_time += time - at[i];
            count = 0;
        }

        // Logic to move to the next process
        if (i == n - 1) {
            i = 0;
        } else if (at[i + 1] <= time) {
            i++;
        } else {
            i = 0;
        }
    }

    printf("\nAverage Waiting Time = %.2f\n", (float)wait_time / n);
    printf("Average Turnaround Time = %.2f\n", (float)turnaround_time / n);

    return 0;
}
