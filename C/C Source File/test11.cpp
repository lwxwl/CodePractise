#include "test11.h"
#include <stdio.h>
// 编写程序，从键盘上输入一行字符，并依次显示在屏幕上。

void main()
{
    char ch;
    ch = getchar();

    while(ch != '\n')
    {
        putchar(ch);
        ch = getchar();   // 输出字符，再取下一输入字符
    }
}

