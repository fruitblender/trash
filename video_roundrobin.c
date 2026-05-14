#include <stdio.h>

int main() {

    int n = 4;

    int bt[] = {10,4,6,3};

    int rt[] = {10,4,6,3};

    int ct[4];

    int quantum = 3;

    int time = 0;

    int done;

    // Arrays for Gantt Chart
    int process[100];
    int gantt_time[100];
    int k = 0;

    gantt_time[k] = 0;

    while (1) {

        done = 1;

        for (int i = 0; i < n; i++) {

            if (rt[i] > 0) {

                done = 0;

                process[k] = i;

                if (rt[i] > quantum) {

                    time += quantum;

                    rt[i] -= quantum;
                }

                else {

                    time += rt[i];

                    ct[i] = time;

                    rt[i] = 0;
                }

                k++;
                gantt_time[k] = time;
            }
        }

        if (done == 1)
            break;
    }

    float avg_tat = 0;

    printf("\nJob\tBT\tCT\tTAT\n");

    for (int i = 0; i < n; i++) {

        avg_tat += ct[i];

        printf("J%d\t%d\t%d\t%d\n",
               i+1,
               bt[i],
               ct[i],
               ct[i]);
    }

    avg_tat /= n;

    printf("\nAverage Turnaround Time = %.2f\n",
           avg_tat);

    // Gantt Chart Printing
    printf("\n\nGantt Chart:\n\n");

    for(int i = 0; i < k; i++) {
        printf("|  J%d  ", process[i] + 1);
    }
    printf("|\n");

    for(int i = 0; i <= k; i++) {
        printf("%-6d", gantt_time[i]);
    }

    return 0;
}