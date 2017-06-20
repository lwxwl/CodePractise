#include <iostream>
using namespace std;

int isLeap(int year)
{
    if (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0)) {
        cout << "29" << endl;
    } else {
        cout << "28" << endl;
    }
    return 0;
}

int main()
{
    int year, month;
    cout << "Please input the year and the month: " << endl;
    cin >> year >> month;
    switch (month) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            cout << "31" << endl;
            break;
        case 2:
            isLeap(year);
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            cout << "30" << endl;
            break;
    }
    return 0;
}

