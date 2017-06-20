#include <iostream>
using namespace std;

int main()
{
    double PI = 0;
    int i;
    for (i = 1; 1.0 / (2 * i - 1) >= 1e-8; i++) {
        PI += 1.0 / (2 * i - 1) * (i % 2 ? 1 : -1);
    }
    PI *= 4;
    cout << PI << endl;
    return 0;
}

