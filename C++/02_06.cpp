#include<iostream>
using namespace std;

int main()
{
    for (int x = 0; x <= 100/5; x++)
    {
        double y = (200 - 14 * x) / 8.0;
        double z = 100 - y - x;
        if (y == int(y) && y >= 0 && z >= 0)
            cout << x << " " << y << " " << z << endl;
    }
    
    return 0;
}
