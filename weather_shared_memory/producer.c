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
                   0666 | IPC_CREAT);

    if (shmid < 0) {

        perror("shmget failed");
        exit(1);
    }

    temp = (int*) shmat(shmid,
                        NULL,
                        0);

    int values[5] = {25,27,29,31,28};

    printf("Writing temperatures:\n");

    for (int i = 0; i < 5; i++) {

        temp[i] = values[i];

        printf("%d\n", temp[i]);
    }

    shmdt(temp);

    return 0;
}