#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <sys/wait.h>

int main() {

    int fd[2];
    pid_t pid;

    char message[] = "Hello from parent";

    char buffer[100];

    if (pipe(fd) < 0) {
        perror("Pipe failed");
        exit(1);
    }

    pid = fork();

    if (pid < 0) {

        perror("Fork failed");
        exit(1);
    }

    else if (pid == 0) {

        close(fd[1]);

        read(fd[0],
             buffer,
             sizeof(buffer));

        printf("Child received: ");

        for (int i = 0;
             buffer[i] != '\0';
             i++) {

            buffer[i] =
                toupper(buffer[i]);
        }

        printf("%s\n", buffer);

        close(fd[0]);
    }

    else {

        close(fd[0]);

        write(fd[1],
              message,
              strlen(message) + 1);

        close(fd[1]);

        wait(NULL);
    }

    return 0;
}