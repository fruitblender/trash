//run this first, then serialise
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void* headlines(void* arg) {

    char* source = (char*)arg;

    for (int i = 1; i <= 5; i++) {

        printf("%s Headline %d\n",
               source,
               i);

        usleep(100000);
    }

    pthread_exit(NULL);
}

int main() {

    pthread_t t1, t2, t3;

    pthread_create(&t1, NULL,
                   headlines,
                   "BBC");

    pthread_create(&t2, NULL,
                   headlines,
                   "CNN");

    pthread_create(&t3, NULL,
                   headlines,
                   "Reuters");

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);

    return 0;
}

//gcc news_aggregator_unserialised.c -o news_aggregator_unserialised -pthread