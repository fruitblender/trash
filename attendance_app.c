#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/wait.h>

int main() {

    int fd;
    pid_t pid;

    pid = fork();

    if (pid < 0) {

        perror("Fork failed");
        exit(1);
    }

    else if (pid == 0) {

        printf("Child Process\n");

        printf("Child PID = %d\n", getpid());

        printf("Parent PID = %d\n", getppid());

        fd = open("attendance.txt",
                  O_WRONLY | O_CREAT | O_APPEND,
                  0644);

        if (fd < 0) {
            perror("File open error");
            exit(1);
        }

        char child_msg[] =
            "Child attended\n";

        write(fd,
              child_msg,
              strlen(child_msg));

        close(fd);
    }

    else {

        wait(NULL);

        printf("Parent Process\n");

        printf("Parent PID = %d\n", getpid());

        printf("Child PID = %d\n", pid);

        fd = open("attendance.txt",
                  O_WRONLY | O_CREAT | O_APPEND,
                  0644);

        if (fd < 0) {
            perror("File open error");
            exit(1);
        }

        char parent_msg[] =
            "Parent attended\n";

        write(fd,
              parent_msg,
              strlen(parent_msg));

        close(fd);
    }

    return 0;
}