#include <iostream>
using namespace std;

int main() {
    int x, y, t;
    cin >> x >> y;
    // t = x;
    // x = y;
    // y = t;
    x += y;
    y = x - y;
    x -= y;
    cout << x << " " << y;
}

