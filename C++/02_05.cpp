#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Please input a score: ";
    cin >> n;
    switch (n / 10)
    {
        case 7:
            cout << "The degree is C" << endl;
            break;
        case 8:
            cout << "The degree is B" << endl;
            break;
        case 9:
        case 10:
            cout << "The degree is C" << endl;
            break;
        default:
            cout << "The degree is D" << endl;
            break;
    }
    return 0;
}

