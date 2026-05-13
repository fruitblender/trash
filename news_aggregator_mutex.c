#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t lock;

void* headlines(void* arg) {

    char* source = (char*)arg;

    pthread_mutex_lock(&lock);

    for (int i = 1; i <= 5; i++) {

        printf("%s Headline %d\n",
               source,
               i);

        usleep(100000);
    }

    pthread_mutex_unlock(&lock);

    pthread_exit(NULL);
}

int main() {

    pthread_t t1, t2, t3;

    pthread_mutex_init(&lock, NULL);

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

    pthread_mutex_destroy(&lock);

    return 0;
}

// Without Mutex, 
// Interleaved 
// Concurrent printing	
// Faster	
// With Mutex
// Serialized
// One thread at a time
// Slower but organized