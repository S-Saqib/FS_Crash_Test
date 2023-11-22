#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#define BLOCK_SIZE 4096
#define BLOCK_COUNT 1000000
#define PARENTDIRPATH "/sheepdog/sbd/dj0/"
#define FILENAME "foo.txt"

int main(int argc, char *argv[]) {
    int fd;
    ssize_t bytes_written;

    char FILEPATH[100] = "";
    if (argc >= 2) {
        strcpy(FILEPATH, argv[1]);
    }
    else {
        strcpy(FILEPATH, PARENTDIRPATH);
        strcat(FILEPATH, FILENAME);
    }

    int numberOfBlocks = 0;
    if (argc >= 3) {
        numberOfBlocks = atoi(argv[2]);
    }
    else {
        numberOfBlocks = BLOCK_COUNT;
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

    // Fill blocks with 'B'
    memset(block1, 'B', BLOCK_SIZE);

    // Write blocks to the file
    while(numberOfBlocks--) {
        bytes_written = write(fd, block1, BLOCK_SIZE);
        if (bytes_written == -1) {
            perror("Error writing block 1");
            exit(EXIT_FAILURE);
        }
        //sleep(0.5); // Sleep for 2 seconds
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
