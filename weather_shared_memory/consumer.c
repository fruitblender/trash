#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main() {

    key_t key = 1234;

    int shmid;

    int *temp;

    shmid = shmget(key,
                   5 * sizeof(int),
                   0666);

    if (shmid < 0) {

        perror("shmget failed");
        exit(1);
    }

    temp = (int*) shmat(shmid,
                        NULL,
                        0);

    printf("Reading temperatures:\n");

    for (int i = 0; i < 5; i++) {

        printf("%d\n", temp[i]);
    }

    shmdt(temp);

    shmctl(shmid,
           IPC_RMID,
           NULL);

    return 0;
}

//open two terminals for both producer and consumer, run producer first, then consumer