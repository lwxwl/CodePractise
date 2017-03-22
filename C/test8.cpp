#include "test8.h"
#include <stdio.h>
// “水仙花数”是指一个三位数，它的三个数位数字的立方和这个数的数值相等，编程打印所有的水仙花数。

void main()
{
    int x, b0, b1, b2;

    printf("The numbers are: ");

    for(x = 100; x <= 999; x++)
    {
        b2 = x/100;              // 最高位
        b1 = (x - b2*100)/10;    // 中间位
        b0 = x%10;               // 最低位

        if(x == b2*b2*b2 + b1*b1*b1 + b0*b0*b0)
            printf("%d", x);
    }

    printf("\n")
}
