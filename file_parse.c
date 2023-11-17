#include <stdio.h>
#include <string.h>

#define PARENTDIRPATH "/sheepdog/sbd/dj0/"
#define FILENAME "foo.txt"

int main(int argc, char *argv[]) {
    FILE *file;
    char currentChar, prevChar;
    int count;

    // Open the file for reading
    char FILEPATH[100] = "";
    if (argc == 2) {
        strcpy(FILEPATH, argv[0]);
    }
    else {
        strcpy(FILEPATH, PARENTDIRPATH);
        strcat(FILEPATH, FILENAME);
    }
    
    file = fopen(FILEPATH, "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    // Initialize variables
    count = 0;
    prevChar = '\0';  // Set to a character that won't match any valid input

    // Read characters from the file
    while ((currentChar = fgetc(file)) != EOF) {
        // Check if the current character is the same as the previous one
        if (currentChar == prevChar) {
            count++;
        } else {
            // Print the count and reset it when a new character is encountered
            if (count > 0) {
                printf("%c: %d\n", prevChar, count);
            }
            count = 1;  // Reset count for the new character
        }

        // Update the previous character
        prevChar = currentChar;
    }

    // Print the count for the last character in the file
    if (count > 0) {
        printf("%c: %d\n", prevChar, count);
    }

    // Close the file
    fclose(file);

    return 0;
}

