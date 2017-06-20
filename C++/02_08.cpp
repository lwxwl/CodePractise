#include <iostream>
using namespace std;

int main() {
    int a, b = 0, i;
    cin >> a;

    for (i = 0; i < 10; i++) {
        if (a > 0) {
            b = b * 10 + a % 10;
            a /= 10;
        } else {
            break;
        }
    }
    cout << "有" << i << "位, 逆向输出: " << b << endl;
    return 0;
}