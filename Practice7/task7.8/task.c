#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

void deleteFile(char *filename) {
    char choice;
    printf("Чи хочете ви видалити файл '%s'? (y/n): ", filename);
    scanf(" %c", &choice);

    if (choice == 'y' || choice == 'Y') {
        if (remove(filename) == 0) {
            printf("Файл '%s' успішно видалено.\n", filename);
        } else {
            perror("Помилка при видаленні файлу");
        }
    }
}

void deleteAllFiles(const char *dirPath) {
    DIR *dir = opendir(dirPath);
    struct dirent *entry;

    if (dir == NULL) {
        perror("Не вдалося відкрити каталог");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        deleteFile(entry->d_name);
    }

    closedir(dir);
}

int main() {
    char choice;

    printf("Виберіть дію:\n");
    printf("1. Видалити один файл\n");
    printf("2. Видалити всі файли в поточному каталозі\n");
    printf("3. Вийти\n");
    printf("Ваш вибір: ");
    scanf(" %c", &choice);

    switch (choice) {
        case '1': {
            char filename[256];
            printf("Введіть ім'я файлу для видалення: ");
            scanf("%s", filename);
            deleteFile(filename);
            break;
        }
        case '2':
            deleteAllFiles(".");
            break;
        case '3':
            printf("Вихід з програми.\n");
            break;
        default:
            printf("Невірний вибір.\n");
    }

    return 0;
}
