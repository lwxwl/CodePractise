#include <iostream>
using namespace std;

int main()
{
    char str[100];
    cin >> str;
    int n = strlen(str);
    for (int i = 0; i < n; i++) {
        cout << str[n - i - 1];
    }
    return 0;
}
