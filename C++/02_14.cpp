#include <iostream>
using namespace std;

int main() {
    int i, n;
    while (1) {
        cin >> n;
        if (n <= 1) {
            break;
        }
        for (i = 2; i < n; i++) {
            if (n % i == 0) {
                break;
            }
        }
        i >= n ? cout << n << "\tis\n" : cout << n << "\tis not\n";
    }
    return 0;
}