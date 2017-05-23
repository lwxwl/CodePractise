// 从键盘输入一个字符串，然后按照下面要求输出一个新字符串。
// 新串是在原串中每两个字符之间插入一个空格，如原串为abcd，则新串为a口b口c口d(口代表空格)。
// 要求在函数insert中完成新串的产生；并在函数中完成所有相应的输入和输出。
include<stdio.h>
#include<stdlib.h>

int main(void) {
    char str[100];
    char *p = str;
    scanf("%s", str);

    while(*p != 0){
        printf("%c ", *p++);
    }

    printf("\n");
}
