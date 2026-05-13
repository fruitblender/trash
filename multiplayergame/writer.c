#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>

int main() {

    const char *name = "/gamescore";

    int shm_fd;

    int *score;

    shm_fd = shm_open(name,
                      O_CREAT | O_RDWR,
                      0666);

    ftruncate(shm_fd,
              sizeof(int));

    score = mmap(0,
                 sizeof(int),
                 PROT_WRITE,
                 MAP_SHARED,
                 shm_fd,
                 0);

    int values[3] = {100,200,300};

    for (int i = 0; i < 3; i++) {

        *score = values[i];

        printf("Writer updated score = %d\n",
               *score);

        sleep(1);
    }

    munmap(score,
           sizeof(int));

    close(shm_fd);

    return 0;
}