#include <stdio.h>

int main() {

    int n = 4;
    int m = 2;

    int allocation[4][2] = {

        {1,0},
        {2,1},
        {1,1},
        {0,2}
    };

    int max[4][2] = {

        {3,2},
        {2,2},
        {3,3},
        {1,2}
    };

    int available[2] = {2,1};

    int need[4][2];

    int finish[4] = {0};

    int safeSeq[4];

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < m; j++) {

            need[i][j] =
                max[i][j] - allocation[i][j];
        }
    }

    int count = 0;

    while (count < n) {

        int found = 0;

        for (int i = 0; i < n; i++) {

            if (finish[i] == 0) {

                int possible = 1;

                for (int j = 0; j < m; j++) {

                    if (need[i][j] >
                        available[j]) {

                        possible = 0;
                        break;
                    }
                }

                if (possible) {

                    for (int j = 0; j < m; j++) {

                        available[j] +=
                            allocation[i][j];
                    }

                    safeSeq[count] = i;

                    finish[i] = 1;

                    count++;

                    found = 1;
                }
            }
        }

        if (!found) {

            printf("System is in deadlock\n");

            return 0;
        }
    }

    printf("Safe sequence: ");

    for (int i = 0; i < n; i++) {

        printf("P%d ", safeSeq[i]);
    }

    printf("\n");

    return 0;
}

// Need=Max−Allocation