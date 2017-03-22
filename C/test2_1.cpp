#include "test2.h"
#include <stdio.h>
#include <math.h>
// 用三种循环结构分别编写程序，计算л的近似值，公式如下：
// л/4 ≈ 1 – 1/3 + 1/5 – 1/7 +
// 到最后一项的绝对值小于10-6为止。

void main()
{
    float pi, t, n;
    int sign = 1;      // 符号
    n = 1.0;           // 每一项的分母
    t = 1.0;           // 每一项的数值
    pi = 0.0;

    while (fabs(t) >= 1e-6) {
        t = sign/n;
        pi += t;
        n += 2;
        sign = -sign;
    }

    pi = pi*4;
    printf("pi = %f\n", pi);
}

