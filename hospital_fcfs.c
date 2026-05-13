#include <stdio.h>

int main() {

    int n = 5;

    int at[] = {0,1,2,3,4};

    int bt[] = {6,4,2,3,1};

    int wt[5], tat[5], ct[5];

    float avg_wt = 0;

    ct[0] = at[0] + bt[0];

    tat[0] = ct[0] - at[0];

    wt[0] = tat[0] - bt[0];

    for (int i = 1; i < n; i++) {

        ct[i] = ct[i-1] + bt[i];

        tat[i] = ct[i] - at[i];

        wt[i] = tat[i] - bt[i];
    }

    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");

    for (int i = 0; i < n; i++) {

        avg_wt += wt[i];

        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               i+1,
               at[i],
               bt[i],
               ct[i],
               tat[i],
               wt[i]);
    }

    avg_wt /= n;

    printf("\nAverage Waiting Time = %.2f\n",
           avg_wt);

    printf("\nGantt Chart:\n");

    printf("0");

    for (int i = 0; i < n; i++) {

        printf(" --P%d-- %d",
               i+1,
               ct[i]);
    }

    printf("\n");

    return 0;
}