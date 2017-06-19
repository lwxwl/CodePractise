#include <iostream>
using namespace std;

int main() {
    int x, y, z, max;
    cout << "Please input three numbers: ";
    cin >> x >> y >> z;
    // max = x > y ? x : y;
    // max = max > z ? max : z;
    max = x >= y && x >= z ? x : y >= x && y >=z ? y : z;
    cout << max;
    return 0;
}

