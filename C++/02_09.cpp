#include <iostream>
using namespace std;

int main()
{
    int temp, a, b = 0;
    cin >> a;
    temp = a;
    for (int i = 0; i < 10; i++) {
        if (temp > 0) {
            b = b * 10 + temp % 10;
            temp /= 10;
        } else {
            break;
        }
    }
    if (a == b) {
        cout << "yes";
    } else {
        cout << "no";
    }
    return 0;
}

