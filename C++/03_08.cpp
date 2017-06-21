#include <iostream>
using namespace std;

bool palindrome(char *str)
{
    int n = strlen(str);
    for (int i = 0; i < n/2; i++) {
        if (str[i] != str[n-i-1])
            return false;
        return true;
    }
}

int main()
{
    char s1[100];
    cin >> s1;
    if (palindrome(s1)) {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }
    return 0;
}

