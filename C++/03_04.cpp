#include <iostream>
using namespace std;

int main()
{
    char str[100];
    cin >> str;
    for (int i = 0, j = 0; str[i] != '0'; i++) {
        if (str[i] == 'c') {
            i--;
        } else {
            str[i] = str[j];
        }
    }
    cout << str << endl;
    return 0;
}

