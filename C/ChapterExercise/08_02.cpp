#include <stdio.h>

int sum();

int main() {
    int tot;

    tot = sum();
    if (tot == -1) {
        printf("\nnot selected!\n");
    } else {
        printf("\nthe result is : %d\n", tot);
    }
    return 0;
}

int sum() {
    int tot = 0;
    char key;

    key = getchar();
    if (key != '0' && key != '1') {
        return -1;
    }
    for (int i = (key == '0') ? 2 : 1; i < 100; i += 2) {
        tot += i;
    }
    return tot;
}
