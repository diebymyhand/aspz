#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_FILE_SIZE 128
#define FILENAME "dice_rolls.txt"

int main() {
    FILE *file = fopen(FILENAME, "w");
    if (!file) {
        perror("Error opening file");
        return 1;
    }

    srand(time(NULL));

    while (1) {
        int roll = rand() % 6 + 1;
        long position = ftell(file); // 

        if (position < 0 || position + 4 > MAX_FILE_SIZE) {
            break;
        }

        if (fprintf(file, "%d\n", roll) < 0) {
            perror("Write error");
            fclose(file);
            return 1;
        }

        fflush(file);  
    }

    long final_size = ftell(file);
    fclose(file);

    printf("File filled up to max size: %ld bytes.\n", final_size);
    return 0;
}
