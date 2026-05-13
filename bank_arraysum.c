#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define SIZE 100
#define THREADS 4

int arr[SIZE];
int partial_sum[THREADS];

typedef struct {
    int start;
    int end;
    int thread_no;
} ThreadData;

void* calculate_sum(void* arg) {

    ThreadData* data = (ThreadData*)arg;

    int sum = 0;

    for (int i = data->start;
         i < data->end;
         i++) {

        sum += arr[i];
    }

    partial_sum[data->thread_no] = sum;

    printf("Thread %d calculated sum = %d\n",
           data->thread_no,
           sum);

    pthread_exit(NULL);
}

int main() {

    pthread_t threads[THREADS];
    ThreadData td[THREADS];

    for (int i = 0; i < SIZE; i++) {
        arr[i] = i + 1;
    }

    int chunk = SIZE / THREADS;

    for (int i = 0; i < THREADS; i++) {

        td[i].start = i * chunk;
        td[i].end = (i + 1) * chunk;
        td[i].thread_no = i;

        pthread_create(&threads[i],
                       NULL,
                       calculate_sum,
                       &td[i]);
    }

    for (int i = 0; i < THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    int total = 0;

    for (int i = 0; i < THREADS; i++) {
        total += partial_sum[i];
    }

    printf("\nTotal Sum = %d\n", total);

    return 0;
}