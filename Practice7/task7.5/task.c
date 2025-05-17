#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

void list_files(const char *path) {
    DIR *dir = opendir(path);
    struct dirent *entry;
    struct stat statbuf;
    
    if (dir == NULL) {
        perror("opendir");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char full_path[1024];
        snprintf(full_path, sizeof(full_path), "%s/%s", path, entry->d_name);

        if (stat(full_path, &statbuf) == 0) {
            if (S_ISDIR(statbuf.st_mode)) {
                printf("Каталог: %s\n", full_path);
                list_files(full_path);
            } else {
                printf("Файл: %s\n", full_path);
            }
        } else {
            perror("stat");
        }
    }

    closedir(dir);
}

int main() {
    const char *dir_path = ".";
    list_files(dir_path);
    return 0;
}
