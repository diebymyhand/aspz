#include <stdio.h>
#include <stdlib.h>

int main() {
    void *ptr = NULL;
    int i = 0;

    while (i < 3) {
        ptr = malloc(16);
        if (!ptr) {
            perror("malloc");
            exit(1);
        }

        printf("Ітерація %d: ptr = %p\n", i + 1, ptr);

        ((char *)ptr)[0] = 'A';
        printf("ptr[0] = %c\n", ((char *)ptr)[0]);

        free(ptr);
        ptr = NULL;
        
        i++;
    }

    return 0;
}
