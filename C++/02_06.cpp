#include <iostream>
using namespace std;

int main()
{
    const int hen = 33, chick = 100;
    for (int i = 0; i <= hen; i++) {
        for (int j = 0; j <= chick; j++) {
            if ((5 * (100 - i - j) + 3 * i + j / 3) == 100 && j / 3 == 0 && i + j <= 100) {
                cout << 100 - i - j << "\t" << i << "\t" << j << endl;
            }
        }
    }
    return 0;
}

