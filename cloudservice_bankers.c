#include <stdio.h>

int main() {

    int n = 4;
    int m = 3;

    int allocation[4][3] = {

        {1,1,0},
        {1,0,1},
        {1,1,1},
        {0,0,1}
    };

    int max[4][3] = {

        {3,2,1},
        {1,2,2},
        {3,3,3},
        {1,1,2}
    };

    int available[3] = {2,1,1};

    int request[3] = {1,0,2};

    int process = 2;

    int need[4][3];

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < m; j++) {

            need[i][j] =
                max[i][j] - allocation[i][j];
        }
    }

    for (int j = 0; j < m; j++) {

        if (request[j] >
            need[process][j]) {

            printf("Request exceeds need\n");

            return 0;
        }

        if (request[j] >
            available[j]) {

            printf("Request denied\n");

            return 0;
        }
    }

    for (int j = 0; j < m; j++) {

        available[j] -= request[j];

        allocation[process][j] += request[j];

        need[process][j] -= request[j];
    }

    int finish[4] = {0};

    int safeSeq[4];

    int count = 0;

    while (count < n) {

        int found = 0;

        for (int i = 0; i < n; i++) {

            if (!finish[i]) {

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

                    safeSeq[count++] = i;

                    finish[i] = 1;

                    found = 1;
                }
            }
        }

        if (!found) {

            printf("Request denied\n");

            return 0;
        }
    }

    printf("Request granted\n");

    printf("Safe sequence: ");

    for (int i = 0; i < n; i++) {

        printf("P%d ", safeSeq[i]);
    }

    printf("\n");

    return 0;
}