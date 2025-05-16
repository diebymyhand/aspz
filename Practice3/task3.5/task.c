#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Program need two arguments\n");
        return 1;
    }

    const char *source_file = argv[1];
    const char *destination_file = argv[2];

    FILE *source = fopen(source_file, "r");
    if (source == NULL) {
        printf("Cannot open file %s for reading\n", source_file);
        return EXIT_FAILURE;
    }

    FILE *destination = fopen(destination_file, "w");
    if (destination == NULL) {
        fclose(source);
        printf("Cannot open file %s for writing\n", destination_file);
        return EXIT_FAILURE;
    }

    char buffer[BUFFER_SIZE];
    size_t bytesRead, bytesWritten;

    while ((bytesRead = fread(buffer, 1, BUFFER_SIZE, source)) > 0) {
        bytesWritten = fwrite(buffer, 1, bytesRead, destination);
        if (bytesWritten != bytesRead) {
            printf("Write error: %s\n", strerror(errno));
            fclose(source);
            fclose(destination);
            return 1;
        }
    }

    fclose(source);
    fclose(destination);
    return 0;
}
