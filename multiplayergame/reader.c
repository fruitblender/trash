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
                      O_RDONLY,
                      0666);

    score = mmap(0,
                 sizeof(int),
                 PROT_READ,
                 MAP_SHARED,
                 shm_fd,
                 0);

    for (int i = 0; i < 3; i++) {

        printf("Reader sees score = %d\n",
               *score);

        sleep(1);
    }

    munmap(score,
           sizeof(int));

    close(shm_fd);

    shm_unlink(name);

    return 0;
}

//two terminals: reader and writer