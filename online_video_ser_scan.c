#include <stdio.h>
#include <stdlib.h>

void sort(int arr[], int n) {

    for (int i = 0; i < n-1; i++) {

        for (int j = 0; j < n-i-1; j++) {

            if (arr[j] > arr[j+1]) {

                int temp = arr[j];

                arr[j] = arr[j+1];

                arr[j+1] = temp;
            }
        }
    }
}

int main() {

    int req[] = {176,79,34,60,92,11,41,114};

    int n = 8;

    int head = 50;

    int total = 0;

    sort(req, n);

    printf("SCAN Service Order:\n");

    for (int i = 0; i < n; i++) {

        if (req[i] > head) {

            total += abs(head - req[i]);

            head = req[i];

            printf("%d ", head);
        }
    }

    for (int i = n-1; i >= 0; i--) {

        if (req[i] < 50) {

            total += abs(head - req[i]);

            head = req[i];

            printf("%d ", head);
        }
    }

    printf("\n");

    printf("Total Head Movement = %d\n",
           total);

    return 0;
}