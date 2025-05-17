#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp_rwho, *fp_more;
    char buffer[256];

    fp_rwho = popen("rwho", "r");
    if (fp_rwho == NULL) {
        perror("popen rwho");
        return 1;
    }

    fp_more = popen("more", "w");
    if (fp_more == NULL) {
        perror("popen more");
        pclose(fp_rwho);
        return 1;
    }

    while (fgets(buffer, sizeof(buffer), fp_rwho) != NULL) {
        fputs(buffer, fp_more);
    }

    pclose(fp_rwho);
    pclose(fp_more);

    return 0;
}
