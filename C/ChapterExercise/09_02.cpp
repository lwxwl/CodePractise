#include <stdio.h>

int main() {
    short int a[2][3] = {{1, 2, 3}, {4, 5, 6}};
    short int (*p)[3];

    p = a;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            printf("a[%d][%d] = %d ", i, j, p[i][j]);
        }
        printf("\n");
    }
    p++;
    for (int j = 0; j < 3; j++) {
        printf("%d ", p[0][j]);
    }
}

