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

    int req[] =
        {55,58,39,18,90,160,150,38,184};

    int n = 9;

    int head = 100;

    int total = 0;

    sort(req, n);

    printf("C-SCAN Service Order:\n");

    for (int i = n-1; i >= 0; i--) {

        if (req[i] < head) {

            total += abs(head - req[i]);

            head = req[i];

            printf("%d ", head);
        }
    }

    printf("\nJumping to end...\n");

    total += abs(head - 184);

    head = 184;

    printf("%d ", head);

    for (int i = n-1; i >= 0; i--) {

        if (req[i] > 100) {

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