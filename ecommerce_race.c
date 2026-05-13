//without mutex, should give error
// run this first

#include <stdio.h>
#include <pthread.h>

int counter = 0;

void* increment(void* arg) {

    for (int i = 0; i < 5000; i++) {
        counter++;
    }

    pthread_exit(NULL);
}

int main() {

    pthread_t t1, t2;

    pthread_create(&t1, NULL,
                   increment, NULL);

    pthread_create(&t2, NULL,
                   increment, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Final Counter = %d\n",
           counter);

    return 0;
}

//gcc ecommerce_race.c -pthread