// 编写程序，将任意一个字符串从第一个字符开始间隔地输出该串。例如：字符串是abcdef，那么输出ace。
#include <stdio.h>

int main() {
    char num[1000] = {0};
    gets(num);

    char *p;
    p = num;
    int i = 0;
    while (num[i] != 0) {
        printf("%c", p[i]);
        i += 2;
    }
    return 0;
}
