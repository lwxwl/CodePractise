#include "exercise_4_3.h"
#include <stdio.h>

#define PI 3.14

void main()
{
    float r, c, s;
    scanf("&f", &r);
    c = 2 * PI * r;
    s = PI * r * r;
    printf("c = %f  s = %f\n", c, s);
}
