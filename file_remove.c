#include <stdio.h>
#include <unistd.h>
#define PARENTDIRPATH "/sheepdog/sbd/dj0/"
#define FILENAME "foo.txt"

int main() {
    char *FILEPATH = new char[100];
    strcpy(FILEPATH, PARENTDIRPATH);
    strcat(FILEPATH, FILENAME);

    if (remove(FILEPATH) == 0) {
        // Call fsync to flush changes to disk
        int fd = -1;
        if ((fd = open(PARENTDIRPATH, O_DIRECTORY)) != -1) {
            fsync(fd);
            close(fd);
        } else {
            perror("Error opening parent directory for fsync");
        }
        printf("File '%s' removed successfully.\n", filename);
    } else {
        perror("Error removing file");
    }

    return 0;
}
