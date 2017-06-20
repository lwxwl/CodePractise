#include <iostream>
using namespace std;

int main() {
    unsigned long n, result = 1, next = 1;
    cout << "Please input an interger!" << endl;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        result *= i;
        next = result * (i + 1);
        if (next < result) {
            cout << i << "! =" << result << endl;
            break;
        }
    }
    if (i > n) {
        cout << i - 1 << " ! =" << result << endl;
    }
    return 0;
}
