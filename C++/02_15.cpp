#include <iostream>
using namespace std;

int power(int x, unsigned y)
{
    if (y == 0) {
        return 1;
    } else {
        return x * power(x, y - 1);
    }
}

int main()
{
    int x;
    unsigned y;
    cin >> x >> y;
    if (x == 0) {
        if (y == 0) {
            cout << "Not exist" << endl;
        } else {
            cout << "1" << endl;
        }
    } else {
        cout << power(x, y) << endl;
    }
    return 0;
}
