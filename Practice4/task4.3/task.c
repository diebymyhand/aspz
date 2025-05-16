#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void test_malloc_zero() {
    void *ptr = malloc(0);

    if (ptr == NULL) {
        printf("malloc(0) повернув NULL\n");
    } else {
        printf("malloc(0) повернув вказівник: %p\n", ptr);
        free(ptr);
    }
}

void test_malloc_nonzero() {
    void *ptr = malloc(3);
    if (ptr == NULL) {
        printf("malloc(3) повернув NULL\n");
    } else {
        printf("malloc(3) повернув вказівник: %p\n", ptr);
        free(ptr);
    }
}

int main() {

    test_malloc_zero();

    test_malloc_nonzero();

    return 0;
}