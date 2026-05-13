#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <semaphore.h>

int main() {

    key_t key = 5678;

    int shmid;

    int *counter;

    sem_t *sem;

    shmid = shmget(key,
                   sizeof(int),
                   0666 | IPC_CREAT);

    counter = (int*) shmat(shmid,
                           NULL,
                           0);

    *counter = 0;

    sem = sem_open("/stocksem",
                   O_CREAT,
                   0666,
                   1);

    pid_t pid = fork();

    if (pid == 0) {

        for (int i = 0; i < 10; i++) {

            sem_wait(sem);

            printf("Reader: Counter = %d\n",
                   *counter);

            sem_post(sem);

            usleep(100000);
        }
    }

    else {

        for (int i = 0; i < 10; i++) {

            sem_wait(sem);

            (*counter)++;

            printf("Writer incremented counter\n");

            sem_post(sem);

            usleep(100000);
        }

        wait(NULL);

        shmdt(counter);

        shmctl(shmid,
               IPC_RMID,
               NULL);

        sem_close(sem);

        sem_unlink("/stocksem");
    }

    return 0;
}