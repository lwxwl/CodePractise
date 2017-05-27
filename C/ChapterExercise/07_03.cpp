// 选择排序
// 依此找出最小的数，放在第一位
#include <stdio.h>

int main() {
    int n = 10;
    int a[n], min, temp;

    printf("input %d numbers: \n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    for (int i = 0; i < n - 1; i++) {
        min = i;
        for (int j = i + 1; j < n; j++) {
            if (a[min] > a[j]) {
                min = j;
            }
        }
        if (min != i) {
            temp = a[i];
            a[i] = a[min];
            a[min] = temp;
        }
    }
    printf("the sorted numbers: \n");
    for (int i = 0; i < n; i++) {
        printf("%d", a[i]);
    }
    return 0;
}
