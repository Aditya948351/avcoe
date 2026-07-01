#include <stdio.h>

int main() {
    int n, tq, bt[20], rem_bt[20], at[20], wt[20], tat[20];
    int t = 0, count = 0, i;
    float total_wt = 0, total_tat = 0;

    printf("Enter total number of processes: ");
    scanf("%d", &n);

    printf("Enter Time Quantum: ");
    scanf("%d", &tq);

    printf("Enter Arrival Time and Burst Time for each process:\n");
    for (i = 0; i < n; i++) {
        printf("P%d Arrival Time: ", i + 1);
        scanf("%d", &at[i]);
        printf("P%d Burst Time: ", i + 1);
        scanf("%d", &bt[i]);
        rem_bt[i] = bt[i];     // Remaining burst time
        wt[i] = 0;
    }

    int done;
    printf("\nGantt Chart: ");

    do {
        done = 1;
        for (i = 0; i < n; i++) {
            if (rem_bt[i] > 0 && at[i] <= t) {
                done = 0;
                if (rem_bt[i] > tq) {
                    printf(" | P%d ", i + 1);
                    t += tq;
                    rem_bt[i] -= tq;
                } else {
                    printf(" | P%d ", i + 1);
                    t += rem_bt[i];
                    wt[i] = t - bt[i] - at[i];
                    rem_bt[i] = 0;
                    tat[i] = t - at[i];
                }
            }
        }
        // If no process was ready at this time, increment time
        if (done == 1) {
            t++;
            done = 0;
        }
    } while (1) {
        done = 1;
        for (i = 0; i < n; i++)
            if (rem_bt[i] > 0)
                done = 0;
        if (done == 1)
            break;
    }

    printf("|\n");

    printf("\nProcess\tAT\tBT\tWT\tTAT\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\n", i + 1, at[i], bt[i], wt[i], tat[i]);
        total_wt += wt[i];
        total_tat += tat[i];
    }

    printf("\nAverage Waiting Time = %.2f", total_wt / n);
    printf("\nAverage Turnaround Time = %.2f\n", total_tat / n);

    return 0;
}
