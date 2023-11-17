#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/time.h>

#define BLOCK_SIZE 420000000
#define PARENTDIRPATH "/sheepdog/sbd/dj0/"
#define FILENAME "foo.txt"

char block1[BLOCK_SIZE];

int main(int argc, char *argv[]) {
    int fd;
    ssize_t bytes_written;
    struct timeval startTime, endTime;

    char FILEPATH[100] = "";
    if (argc == 2) {
        strcpy(FILEPATH, argv[1]);
    }
    else {
        strcpy(FILEPATH, PARENTDIRPATH);
        strcat(FILEPATH, FILENAME);
    }

    gettimeofday(&startTime, NULL);
    // Open the file for overwriting data
    // fd = open(FILEPATH, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    fd = open(FILEPATH, O_WRONLY);
    if (fd == -1) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    // Fill block 1 with 'B'
    memset(block1, 'B', BLOCK_SIZE);
    bytes_written = write(fd, block1, BLOCK_SIZE);
    if (bytes_written == -1) {
        perror("Error writing block 1");
        exit(EXIT_FAILURE);
    }
    gettimeofday(&endTime, NULL);
    double elapsedTime = endTime.tv_sec - startTime.tv_sec + (endTime.tv_usec - startTime.tv_usec)/1.0e6;
    printf("%.4f s: Data written\n", elapsedTime);

    // Perform fsync to flush changes to disk
    if (fsync(fd) == -1) {
        perror("Error during fsync");
        exit(EXIT_FAILURE);
    }
    gettimeofday(&endTime, NULL);
    elapsedTime = endTime.tv_sec - startTime.tv_sec + (endTime.tv_usec - startTime.tv_usec)/1.0e6;
    printf("%.4f s: Fsync completed successfully.\n", elapsedTime);

    // Close the file
    if (close(fd) == -1) {
        perror("Error closing file");
        exit(EXIT_FAILURE);
    }
    gettimeofday(&endTime, NULL);
    elapsedTime = endTime.tv_sec - startTime.tv_sec + (endTime.tv_usec - startTime.tv_usec)/1.0e6;
    printf("%.4f s: File closed.\n", elapsedTime);

    return 0;
}
