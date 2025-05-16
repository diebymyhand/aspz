#include <stdio.h>
#include <stdlib.h>

int main() {
    size_t size = 1024 * 1024 * 1024;
    char *ptr = malloc(size);
    if (!ptr) {
        perror("malloc");
        return 1;
    }

    printf("malloc успішний: %p\n", ptr);

    size_t new_size = (size_t)-1;
    char *tmp = realloc(ptr, new_size);

    if (tmp == NULL) {
        printf("realloc не вдалося: пам’ять не виділено, ptr залишився валідним\n");
        free(ptr);
    } else {
        ptr = tmp;
        printf("realloc успішний: %p\n", ptr);
        free(ptr);
    }

    return 0;
}
