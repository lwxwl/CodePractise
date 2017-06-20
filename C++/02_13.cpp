#include <iostream>
using namespace std;

double PI(double precision)
{
    double temp = 0;
    for (int i = 1; 1.0 / (2 * i - 1) > precision; i++) {
        temp += 1.0 / (2 * i - 1) * (i % 2 ? 1 : -1);
    }
    return temp * 4;
}

int main()
{
    cout << PI(0.00000001) << endl;
    return 0;
}


