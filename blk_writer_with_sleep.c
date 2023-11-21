#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#define BLOCK_SIZE 4096
#define PARENTDIRPATH "/sheepdog/sbd/dj0/"
#define FILENAME "foo.txt"

int main() {
    int fd;
    ssize_t bytes_written;

    char FILEPATH[100] = "";
    if (argc == 2) {
        strcpy(FILEPATH, argv[1]);
    }
    else {
        strcpy(FILEPATH, PARENTDIRPATH);
        strcat(FILEPATH, FILENAME);
    }

    // Open the file for overwriting data
    // fd = open(FILEPATH, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    fd = open(FILEPATH, O_WRONLY);
    if (fd == -1) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    // Data to be written to the file
    char block1[BLOCK_SIZE];
    char block2[BLOCK_SIZE];

    // Fill block 1 with 'B'
    memset(block1, 'B', BLOCK_SIZE);

    // Fill block 2 with 'B'
    memset(block2, 'B', BLOCK_SIZE);

    // Write two blocks to the file
    bytes_written = write(fd, block1, BLOCK_SIZE);
    if (bytes_written == -1) {
        perror("Error writing block 1");
        exit(EXIT_FAILURE);
    }

    printf("Sleeping for 2 seconds...\n");
    sleep(2); // Sleep for 2 seconds
    printf("Awake!\n");

    bytes_written = write(fd, block2, BLOCK_SIZE);
    if (bytes_written == -1) {
        perror("Error writing block 2");
        exit(EXIT_FAILURE);
    }

    // Perform fsync to flush changes to disk
    if (fsync(fd) == -1) {
        perror("Error during fsync");
        exit(EXIT_FAILURE);
    }

    // Close the file
    if (close(fd) == -1) {
        perror("Error closing file");
        exit(EXIT_FAILURE);
    }

    printf("Data written and fsync completed successfully.\n");

    return 0;
}
