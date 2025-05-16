#include <stdio.h>
#include <stdlib.h>

int main() {
    char *ptr = realloc(NULL, 10);

    if (ptr != NULL) {
        printf("realloc(NULL, 10): пам’ять виділена: %p\n", (void *)ptr);
        free(ptr);
    } else {
        printf("realloc(NULL, 10): не вдалося виділити пам’ять\n");
    }

    ptr = malloc(10);

    void *newptr = realloc(ptr, 0);
    
    if (newptr == NULL) {
        printf("realloc(ptr, 0) повернув NULL (пам’ять звільнена)\n");
    }

    return 0;
}