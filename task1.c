#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *filePtr;
    char character;

    // Step 1: Creating and writing initial data to the file
    filePtr = fopen("datafile.txt", "w");  // Open in write mode
    if (filePtr == NULL) {
        printf("Unable to create file.\n");
        return 1;
    }

    fprintf(filePtr, "Hello, this file is freshly created.\n");
    fprintf(filePtr, "Writing some initial content here.\n");
    fclose(filePtr);
    printf(" File has been created and data written.\n");

    // Step 2: Reading content from the file
    printf("\n Reading file content:\n\n");
    filePtr = fopen("datafile.txt", "r");
    if (filePtr == NULL) {
        printf("Error opening file for reading.\n");
        return 1;
    }

    while ((character = fgetc(filePtr)) != EOF) {
        putchar(character);
    }
    fclose(filePtr);

    // Step 3: Appending additional content
    filePtr = fopen("datafile.txt", "a");  // Open in append mode
    if (filePtr == NULL) {
        printf("Error opening file to append.\n");
        return 1;
    }

    fprintf(filePtr, "Now we are appending some new lines.\n");
    fprintf(filePtr, "Appending ensures old data is preserved.\n");
    fclose(filePtr);
    printf("\n\n New data has been appended.\n");

    // Step 4: Displaying updated content
    printf("\n Updated file content:\n\n");
    filePtr = fopen("datafile.txt", "r");
    if (filePtr == NULL) {
        printf("Error opening file for final reading.\n");
        return 1;
    }

    while ((character = fgetc(filePtr)) != EOF) {
        putchar(character);
    }
    fclose(filePtr);

    return 0;
}
