#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>

#define MAX_PATH_LEN 1024

int compare(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

void list_subdirectories(const char *path) {
    DIR *dir = opendir(path);
    struct dirent *entry;
    struct stat statbuf;
    char *subdirs[1024];
    int subdir_count = 0;

    if (dir == NULL) {
        perror("opendir");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char full_path[MAX_PATH_LEN];
        snprintf(full_path, sizeof(full_path), "%s/%s", path, entry->d_name);

        if (stat(full_path, &statbuf) == 0 && S_ISDIR(statbuf.st_mode)) {
            subdirs[subdir_count] = strdup(entry->d_name);
            subdir_count++;
        }
    }

    qsort(subdirs, subdir_count, sizeof(char *), compare);

    printf("Підкаталоги в каталозі '%s':\n", path);
    for (int i = 0; i < subdir_count; i++) {
        printf("%s\n", subdirs[i]);
        free(subdirs[i]); // Вивільняємо пам'ять
    }

    closedir(dir);
}

int main() {
    const char *dir_path = ".";
    list_subdirectories(dir_path);
    return 0;
}
