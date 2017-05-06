#include "homework2.h"
#include <stdio.h>
// 输入三个实数，判断组成三角形形状。
// 若为正三角形则输出1，为等腰三角形则输出2，为任意三角形则输出3，不能构成三角形则输出0.

void main()
{
    float a, b, c;

    printf("Please input three number( , , ): ");
    scanf("%f, %f, %f", &a, &b, &c);

    if(a+b>c && a+c>b && b+c>a)
    {
        if(a == b && a == c && b == c)
            printf("1\n");
        else if(a == b || a == c || b == c)
            printf("2\n");
        else
            printf("3\n");
    }
    else
        printf("0\n");

}


