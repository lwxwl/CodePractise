#include "homework3.h"
#include <stdio.h>
//  “鸡翁一，值钱五，鸡母一，值钱三，鸡雏三，值钱一，百钱买百鸡，问翁母雏各几何？” (引自张邱建算经，公元五世纪)

void main()
{
    int x, y, z;

    for(x = 0; x <= 20; x++)
    {
        for(y = 0; y <= 33; y++)
            {
            z = 3*(100 - 5*x - 3*y);
            if(z >= 0 && x + y + z = 100)
                printf("%8d %8d %8d\n", x, y, z);
            }
    }
}

