#include <iostream>
using namespace std;

int main()
{
    for (int i = 0; i < 26; i++) {
        cout << char('A' + i) << "\t";
    }
    cout << endl;

    for (int i = 0; i < 26; i++) {
        cout << char('Z' - i) << "\t";
    }
    return 0;
}
