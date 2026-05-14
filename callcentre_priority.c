#include <stdio.h>

typedef struct {

    int pid;
    int bt;
    int pr;
    int wt;
    int tat;

} Process;

int main() {

    int n = 5;

    Process p[] = {

        {1,4,2,0,0},
        {2,3,1,0,0},
        {3,5,3,0,0},
        {4,1,1,0,0},
        {5,2,4,0,0}
    };

    Process temp;

    for (int i = 0; i < n-1; i++) {

        for (int j = i+1; j < n; j++) {

            if (p[i].pr > p[j].pr) {

                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    p[0].wt = 0;

    p[0].tat = p[0].bt;

    for (int i = 1; i < n; i++) {

        p[i].wt =
            p[i-1].wt + p[i-1].bt;

        p[i].tat =
            p[i].wt + p[i].bt;
    }

    float avg_wt = 0;
    float avg_tat = 0;

    printf("\nPID\tBT\tPR\tWT\tTAT\n");

    for (int i = 0; i < n; i++) {

        avg_wt += p[i].wt;

        avg_tat += p[i].tat;

        printf("P%d\t%d\t%d\t%d\t%d\n",
               p[i].pid,
               p[i].bt,
               p[i].pr,
               p[i].wt,
               p[i].tat);
    }

    avg_wt /= n;
    avg_tat /= n;

    printf("\nAverage Waiting Time = %.2f",
           avg_wt);

    printf("\nAverage Turnaround Time = %.2f\n",
           avg_tat);

    // Gantt Chart Printing

    int time = 0;

    printf("\nGantt Chart:\n\n");

    for (int i = 0; i < n; i++) {

        printf("|  P%d  ", p[i].pid);
    }

    printf("|\n");

    printf("0");

    for (int i = 0; i < n; i++) {

        time += p[i].bt;

        printf("%6d", time);
    }

    return 0;
}