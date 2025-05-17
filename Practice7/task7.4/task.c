#include <stdio.h>
#include <stdlib.h>

#define LINES_PER_PAGE 20

void display_file(FILE *file) {
    char line[1024];
    int line_count = 0;
    
    while (fgets(line, sizeof(line), file) != NULL) {
        printf("%s", line);
        line_count++;
        
        if (line_count == LINES_PER_PAGE) {
            printf("\nНатисніть будь-яку клавішу для продовження...");
            getchar();
            line_count = 0;
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Використання: %s <файл1> <файл2> ...\n", argv[0]);
        return 1;
    }

    for (int i = 1; i < argc; i++) {
        FILE *file = fopen(argv[i], "r");
        if (file == NULL) {
            perror("Не вдалося відкрити файл");
            continue;
        }

        printf("\nВиведення з файлу: %s\n", argv[i]);
        display_file(file);
        fclose(file);
    }

    return 0;
}
