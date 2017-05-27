// 冒泡排序
#include <stdio.h>

int main() {
    int n = 10;
    int a[n];
    int flag, temp;

    printf("input %d numbers: \n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i < n - 1; i++) {
        flag = 0;
        for (int j = 0; j < n - i; j++) {
            if (a[j] > a[j + 1]) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                flag = 1;
            }
        }
        if (flag == 0) {
            break;
        }
    }
    printf("the sorted numbers: \n");
    for (int i = 0; i < n; i++) {
        printf("%d", a[i]);
    }
    return 0;
}