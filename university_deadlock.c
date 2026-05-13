#include <stdio.h>

int main() {

    int n = 3;
    int m = 2;

    int allocation[3][2] = {

        {1,0},
        {0,1},
        {1,1}
    };

    int request[3][2] = {

        {0,1},
        {1,0},
        {1,1}
    };

    int available[2] = {0,0};

    int finish[3] = {0};

    int deadlock = 0;

    while (1) {

        int found = 0;

        for (int i = 0; i < n; i++) {

            if (!finish[i]) {

                int possible = 1;

                for (int j = 0; j < m; j++) {

                    if (request[i][j] >
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

                    finish[i] = 1;

                    found = 1;
                }
            }
        }

        if (!found)
            break;
    }

    for (int i = 0; i < n; i++) {

        if (!finish[i]) {

            deadlock = 1;
        }
    }

    if (deadlock) {

        printf("Processes in deadlock: ");

        for (int i = 0; i < n; i++) {

            if (!finish[i]) {

                printf("P%d ", i);
            }
        }

        printf("\n");
    }

    else {

        printf("No deadlock detected\n");
    }

    return 0;
}