#include "homework1.h"
#include <stdio.h>
// 输入两门课的成绩，如果两门成绩都在60分以上,则输出“it is pass.”
// 只要有一门低于60分就输出“it is not pass.”
// 如果输入的任何一门成绩不在0-100范围内则输出“it is error.”。
// (要求用switch语句来编程)

void main()
{
    int a, b;
    int i;

    printf("Please input the scores(the first, the second): ");
    scanf("%d, %d", &a, &b);

    if(a >= 60 && b >= 60)
        i = 1;
    else if(a < 60 || b < 60)
        i = 2;
    else if(a < 0 || b < 0 || a > 100 || b > 100)
        i = 3;

    switch (i) {
    case 1:
        printf("it is pass.\n");
        break;
    case 2:
        printf("it is not pass.\n");
        break;
    case 3:
        printf("it is error.\n");
        break;
    }

}


