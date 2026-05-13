#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define N 3

pthread_mutex_t forks[N];

void* philosopher(void* arg) {

    int id = *(int*)arg;

    int left = id;

    int right = (id + 1) % N;

    printf("Philosopher %d is thinking\n",
           id);

    sleep(1);

    if (id == 0) {

        pthread_mutex_lock(&forks[right]);

        pthread_mutex_lock(&forks[left]);
    }

    else {

        pthread_mutex_lock(&forks[left]);

        pthread_mutex_lock(&forks[right]);
    }

    printf("Philosopher %d is eating\n",
           id);

    sleep(2);

    pthread_mutex_unlock(&forks[left]);

    pthread_mutex_unlock(&forks[right]);

    printf("Philosopher %d finished eating\n",
           id);

    return NULL;
}

int main() {

    pthread_t p[N];

    int ids[N];

    for (int i = 0; i < N; i++) {

        pthread_mutex_init(&forks[i],
                           NULL);
    }

    for (int i = 0; i < N; i++) {

        ids[i] = i;

        pthread_create(&p[i],
                       NULL,
                       philosopher,
                       &ids[i]);
    }

    for (int i = 0; i < N; i++) {

        pthread_join(p[i], NULL);
    }

    for (int i = 0; i < N; i++) {

        pthread_mutex_destroy(&forks[i]);
    }

    return 0;
}