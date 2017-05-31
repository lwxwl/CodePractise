#include <stdio.h>
#include <math.h>

void showerror();

int main() {
    int a;

    scanf("%d", &a);
    while (a < 0) {
        showerror();
        scanf("%d", &a);
    }
    printf("sqrt(a) = %.2f\n", sqrt(a));
    return 0;
}

void showerror() {
    printf("input error!\n");
}
