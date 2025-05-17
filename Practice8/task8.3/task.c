#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int compare(const void *a, const void *b) {
    int *int_a = (int *)a;
    int *int_b = (int *)b;
    return (*int_a - *int_b);
}

void generate_sorted(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = i;
    }
}

void generate_reverse_sorted(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = size - 1 - i;
    }
}

void generate_random(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % size;
    }
}

void test_qsort(int *arr, int size, const char *type) {
    printf("Тестування на масиві типу: %s\n", type);

    // Підрахунок часу виконання сортування
    clock_t start = clock();
    qsort(arr, size, sizeof(int), compare);
    clock_t end = clock();

    for (int i = 1; i < size; i++) {
        if (arr[i-1] > arr[i]) {
            printf("Помилка сортування в масиві!\n");
            return;
        }
    }

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Час сортування: %f секунд\n", time_taken);
}

int main() {
    const int size = 10000;
    int *arr;

    arr = (int *)malloc(size * sizeof(int));

    generate_sorted(arr, size);
    test_qsort(arr, size, "Відсортований");

    generate_reverse_sorted(arr, size);
    test_qsort(arr, size, "Відсортований у зворотному порядку");

    generate_random(arr, size);
    test_qsort(arr, size, "Випадкові");

    for (int i = 0; i < size; i++) {
        arr[i] = 5;
    }
    test_qsort(arr, size, "Однакові елементи");

    free(arr);
    return 0;
}
