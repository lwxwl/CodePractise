#include "homework4.h"
#include <stdio.h>
// 输出下列图形。
// 1  2  3  4  5  6  7  8  9
// 2  3  4  5  6  7  8  9
// 3  4  5  6  7  8  9
// 4  5  6  7  8  9
// 5  6  7  8  9
// 6  7  8  9
// 7  8  9
// 8  9
// 9

void main()
{
    int x, y;

    for(x = 1; x <= 9; x++)
    {
        for(y = x; y <= 9; y++)
            printf("%2d", y);

        printf("\n");
    }
}


