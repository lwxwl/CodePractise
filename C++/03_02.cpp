#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    const int N = 6;
    int a[N][N];
    for (int i = 0; i < N; i++) {
        a[i][0] = 1;
        a[i][i] = 1;
        for (int j = 1; j < i; j++) {
            a[i][j] = a[i-1][j-1] + a[i-1][j];
        }
    }
    for (int i = 0; i < N; i++) {
        cout << setw((N-i)*5/2);
        for (int j = 0; j <= i; j++) {
            cout << a[i][j] << setw(5);
        }
        cout << endl;
    }
    return 0;
}

