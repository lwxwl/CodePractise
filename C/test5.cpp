#include "test5.h"
#include <stdio.h>
#include <math.h>
// 用牛顿迭代法求下面方程在1.5附近的根。
// 2x^3-4x^2+3x-6 = 0
// 牛顿迭代公式为： x1=x0- f(x0)/f’(x0)

void main()
{
    double x1, x0, f1, f2;
    x0 = 1.5;

    do
    {
        x1 = x0;
        f1 = ((2*x1 - 4)*x1 + 3)*x1 - 6;
        f2 = (6*x1 - 8)*x1 + 3;
        x0 = x1 - f1/f2;
    }while(fabs(x1 - x0 >= 1e-5));

    printf("The root is %lf\n", x0);
}

