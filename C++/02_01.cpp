#include <iostream>
using namespace std;

int cToF(int n) {
    cout << "转换后的温度值为: " << (9 / 5.0 * n + 32 + 0.5) << endl;
    return 0;
}

int fToC(int n) {
    cout << "转换后的温度值为: " << (5 / 9.0 * (n - 32) + 0.5) << endl;
    return 0;
}
int main() {
    int i, n;
    cout << "摄氏温度转华氏温度: 1" << endl;
    cout << "华氏温度转摄氏温度: 2" << endl;
    cin >> i;
    cout << "温度值: " << endl;
    cin >> n;
    if (i == 1) {
        cToF(n);
    } else if (i == 2) {
        fToC(n);
    } else {
        cout << "input again !" << endl;
    }
    return 0;
}
