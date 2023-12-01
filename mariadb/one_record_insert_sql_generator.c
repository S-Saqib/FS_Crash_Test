#include <stdio.h>
#include <string.h>

char V_VALUE[15000001]; // One extra for null-termination

int main() {
    const char SQL_FILE[] = "one_record_inserter.sql";
    const char K_VALUE[] = "K_F";

    // Use memset to fill V_VALUE with '1'
    memset(V_VALUE, '1', sizeof(V_VALUE) - 1);

    // Null-terminate the string
    V_VALUE[sizeof(V_VALUE) - 1] = '\0';

    // Create and open SQL file
    FILE *sqlFile = fopen(SQL_FILE, "w");

    // Check if file opening is successful
    if (sqlFile == NULL) {
        return 1; // Return an error code
    }

    // Write SQL query to the file
    fprintf(sqlFile, "INSERT INTO testkv (k, v) VALUES ('%s', '%s');\n", K_VALUE, V_VALUE);

    // Close the file
    fclose(sqlFile);

    return 0; // Return success code
}
