#include <stdio.h>
#include <stdlib.h>

struct sbar {
    int a;
    float b;
};

int main() {
    struct sbar *ptr, *newptr;

    ptr = calloc(1000, sizeof(struct sbar));
    if (!ptr) {
        perror("calloc");
        return 1;
    }

    newptr = reallocarray(ptr, 500, sizeof(struct sbar));
    if (!newptr) {
        perror("reallocarray");
        free(ptr);
        return 1;
    }

    newptr[0].a = 42;
    newptr[0].b = 3.14f;
    printf("newptr[0] = { %d, %.2f }\n", newptr[0].a, newptr[0].b);

    free(newptr);
    return 0;
}
