#include <stdio.h>

int main() {

    int n = 4;

    int bt[] = {10,4,6,3};

    int rt[] = {10,4,6,3};

    int ct[4];

    int quantum = 3;

    int time = 0;

    int done;

    while (1) {

        done = 1;

        for (int i = 0; i < n; i++) {

            if (rt[i] > 0) {

                done = 0;

                if (rt[i] > quantum) {

                    time += quantum;

                    rt[i] -= quantum;
                }

                else {

                    time += rt[i];

                    ct[i] = time;

                    rt[i] = 0;
                }
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

    return 0;
}