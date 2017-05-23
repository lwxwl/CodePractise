// 将一个长度不超过4的数字字符串转换成一个整数。如字符串是“3248”，则转换的整数是3248。
#include <stdio.h>

int main() {
    char a;
    int b = 0;
    char *p;

    scanf("%s", &a);
    p = &a;
    while(*p) {
        b = b * 10 + (*p++) - 48;
    }

    printf("%d", b);
    return 0;
}