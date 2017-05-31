#include <stdio.h>

void cmp(int a, int b);

int main() {
    int i = 2;
    cmp(i, i++);
    printf("i = %d\n", i);
}

void cmp(int a, int b) {
    printf("a = %d, b = %d\n", a, b);
    if (a > b) {
        printf("a > b\n");
    } else if (a == b) {
        printf("a = b\n");
    } else {
        printf("a < b\n");
    }
}

