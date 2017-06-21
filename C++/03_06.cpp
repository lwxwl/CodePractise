#include <iostream>
using namespace std;

int main()
{
    char SStr[100], DStr[100];
    cin >> SStr >> DStr;
    int n1 = strlen(SStr);
    int n2 = strlen(DStr);
    for (int i = 0; i < n2 + 1; i++) {
        SStr[i + n1] = DStr[i];
    }
    cout << SStr;
    return 0;
}
