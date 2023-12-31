#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#define BLOCK_SIZE 409600000
#define PARENTDIRPATH "/sheepdog/sbd/dj0/"
#define FILENAME "foo.txt"
char block1[BLOCK_SIZE];

int main(int argc, char *argv[]) {
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

    // Open the file (create if not exists) for writing
    fd = open(FILEPATH, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    if (fd == -1) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    // Data to be written to the file
    // Fill block 1 with 'A'
    memset(block1, 'A', BLOCK_SIZE);

    // Write two blocks to the file
    bytes_written = write(fd, block1, BLOCK_SIZE);
    if (bytes_written == -1) {
        perror("Error writing block 1");
        exit(EXIT_FAILURE);
    }
    printf("Data written.\n");

    // Perform fsync to flush changes to disk
    if (fsync(fd) == -1) {
        perror("Error during fsync");
        exit(EXIT_FAILURE);
    }
    printf("Fsync completed successfully.\n");

    // Close the file
    if (close(fd) == -1) {
        perror("Error closing file");
        exit(EXIT_FAILURE);
    }
    printf("File closed.\n");

    return 0;
}
