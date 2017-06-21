#include <iostream>
using namespace std;

int main()
{
    const int N = 10;
    int a[N];
    for (int i = 0; i < N; i++) {
        cin >> a[i];
        if (a[i] < 0) {
            break;
        }
    }
    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            if ((a[i] % 2 == a[j] % 2) && a[i] > a[j] || a[i] % 2 < a[j] % 2) {
                int temp;
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    for (int i = 0; i < N; i++) {
        cout << a[i] << "\t";
    }
    return 0;
}
