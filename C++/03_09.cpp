#include <iostream>
using namespace std;

int SubStrNum(char *str, char *substr) {
    int n = 0;
    int len1, len2;
    int p1, p2;
    len1 = strlen(str);
    len2 = strlen(substr);
    p1 = 0;
    while (p1 < len1) {
        p2 = 0;
        while (str[p1] == substr[p2] && p1 < len1 && p2 < len2) {
            p1++;
            p2++;
        }
        if (p1 == len1 && p2 < len2) {
            break;
        }
        if (p2 == len2) {
            n++;
        } else {
            p1 = p1 - p2 + 1;
        }
    }
    return n;
}

int main()
{
    char str[100];
    char substr[10];
    cout << "input source string: ";
    cin >> str;
    cout << "input sub string: ";
    cin >> substr;
    cout << "the result is: " << SubStrNum(str, substr) << endl;
    return 0;
}

