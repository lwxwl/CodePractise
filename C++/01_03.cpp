#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    double i, j;
    cout << "Please input two numbers: ";
    cin >> i >> j;
    cout << setprecision(1);
    cout << "setprecision(1): " << i << "/" << j << "=" << i / j << endl;
    cout << setprecision(2);
    cout << "setprecision(2): " << i << "/" << j << "=" << i / j << endl;
    cout << setprecision(3);
    cout << "setprecision(3): " << i << "/" << j << "=" << i / j << endl;
    cout << setprecision(8);
    cout << "setprecision(8): " << i << "/" << j << "=" << i / j << endl;
    cout << setprecision(9);
    cout << "setprecision(9): " << i << "/" << j << "=" << i / j << endl;
    cout << setprecision(10);
    cout << "setprecision(10): " << i << "/" << j << "=" << i / j << endl;
}

