#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Ім'я користувача (whoami):\n");
    system("whoami");

    printf("\nІнформація про ідентифікатори користувача та групи (id):\n");
    system("id");

    return 0;
}
