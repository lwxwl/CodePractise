#include <stdio.h>

int max(int a, int b);

int main() {
    int a, b, c;

    scanf("%d%d", &a, &b);
    c = max(a, b);
    printf("the biggest number is %d\n", c);
}

int max(int a, int b) {
    return (a > b ? a : b);
}