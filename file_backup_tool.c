#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

#ifndef O_BINARY
#define O_BINARY 0
#endif

#define BUFFER_SIZE 1024

int main() {

    int source_fd, dest_fd;
    ssize_t bytes_read, bytes_written;
    char buffer[BUFFER_SIZE];

    struct stat source_stat, dest_stat;

    source_fd = open("source.txt", O_RDONLY);

    if (source_fd < 0) {
        perror("Error opening source file");
        exit(1);
    }

    dest_fd = open("destination.txt",
                   O_WRONLY | O_CREAT | O_TRUNC | O_BINARY,
                   0644);

    if (dest_fd < 0) {
        perror("Error opening destination file");
        close(source_fd);
        exit(1);
    }

    while ((bytes_read =
            read(source_fd, buffer, BUFFER_SIZE)) > 0) {

        bytes_written =
            write(dest_fd, buffer, bytes_read);

        if (bytes_written != bytes_read) {
            perror("Write error");

            close(source_fd);
            close(dest_fd);

            exit(1);
        }
    }

    if (bytes_read < 0) {
        perror("Read error");
    }

    close(source_fd);
    close(dest_fd);

    if (stat("source.txt", &source_stat) < 0 ||
        stat("destination.txt", &dest_stat) < 0) {

        perror("Stat error");
        exit(1);
    }

    if (source_stat.st_size ==
        dest_stat.st_size) {

        printf("File copied successfully!\n");

        printf("Source Size = %ld bytes\n",
               source_stat.st_size);

        printf("Destination Size = %ld bytes\n",
               dest_stat.st_size);
    }
    else {
        printf("Copy failed!\n");
    }

    return 0;
}

//Create source file: echo "OS Lab" > source.txt
//compile: gcc file_backup_tool.c -o file_backup_tool