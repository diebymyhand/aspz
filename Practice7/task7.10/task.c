#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generateInRangeA() {
    for (int i = 0; i < 5; i++) {
        double random_value = (double)rand() / RAND_MAX;
        printf("Випадкове число від 0.0 до 1.0: %.6f\n", random_value);
    }
}

void generateInRangeB(double n) {
    for (int i = 0; i < 5; i++) {
        double random_value = (double)rand() / RAND_MAX * n;
        printf("Випадкове число від 0.0 до %.2f: %.6f\n", n, random_value);
    }
}

int main() {
    srand(time(NULL));

    printf("Генерація випадкових чисел у діапазоні від 0.0 до 1.0:\n");
    generateInRangeA();

    double n;
    printf("Введіть значення n для генерації випадкових чисел від 0.0 до n: ");
    scanf("%lf", &n);

    printf("Генерація випадкових чисел у діапазоні від 0.0 до %.2f:\n", n);
    generateInRangeB(n);

    return 0;
}
