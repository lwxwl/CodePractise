#include "exercise_4_6.h"
#include <stdio.h>

void main()
{
    unsigned long t, r;
    int d, h, m, s;

    printf("second = ");
    scanf("%d", &t);
    d = t / (24 * 3600);
    r = t % (24 * 3600);
    h = r / 3600;
    m = (r % 3600) / 60;
    s = (r % 3600) % 60;
    printf("passed days: %d, current time is %02d: %02d: %02d\n", d, h, m, s);
}
