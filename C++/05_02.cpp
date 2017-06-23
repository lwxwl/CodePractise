#include <iostream>
#include <cmath>
using namespace std;

class Point {
private:
    double X;
    double Y;
public:
    Point(double x, double y) {
        X = x;
        Y = y;
    }
    double Distance(const Point &p) {
        X -= p.X;
        Y -= p.Y;
        return sqrt(X * X + Y * Y);
    }
};

int main() {
    Point A(1, 2), B(3, 4);
    cout << A.Distance(B) << endl;
    return 0;
}

