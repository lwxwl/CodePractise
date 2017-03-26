#include "test12.h"
#include <stdio.h>
// 编写程序，从键盘输入梯形的上下底边长度和高，计算梯形的面积。

void main()
{
    float a, b, h, s;

    printf("input the length of the first parallel side: ");
    scanf("%f", &a);
    printf("input the length of the second parallel side: ");
    scanf("%f", &b);
    printf("input the length of the height: ");
    scanf("%f", &h);

    s = (a + b)*h/2;

    printf("The area of the trapezoid is %f", s);
}
