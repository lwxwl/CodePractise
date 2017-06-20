#include <iostream>
using namespace std;

int main()
{
    int weight, distance, cost;
    cout << "Please input the weight and the distance: " << endl;
    cin >> weight >> distance;
    switch (weight / 15) {
        case 1:
            cost = 5;
            break;
        case 2:
            cost = 9;
            break;
        case 3:
            cost = 12;
            break;
        case 4:
            cost = 14 + distance / 1000;
            break;
        default:
            cost = 15 + distance / 1000;
            break;
    }
    cout << cost << endl;
    return 0;
}