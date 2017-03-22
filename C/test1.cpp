#include "test1.h"
#include <stdio.h>
#include <conio.h>

//编写程序，从键盘输入一个字符，求出与该字符前后相邻的两个字符，按从小到大的顺序输出这三个字符的ASCII码。
void main()
{
    char ch, ch1, ch2;

    ch = getche();
    putchar('\n');
    ch1 = ch == 'a'? 'z': ch-1;
    ch2 = ch == 'z'? 'a': ch+1;
    printf("%c, %c, %c\n", ch1, ch, ch2);
}
