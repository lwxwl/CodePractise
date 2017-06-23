#include <iostream>
#include <cmath>
using namespace std;

class Triangle {
private:
    double a;
    double b;
    double c;
public:
    Triangle(double x, double y, double z) {
        a = x;
        b = y;
        c = z;
    }
    double GetPerimeter() {
        return a + b + c;
    }
    double GetArea() {
        double p = GetPerimeter() / 2;
        return sqrt(p * (p-a) * (p-b) * (p-c));
    }
    void ShowTriangle() {
        cout << "Perimeter: " << GetPerimeter() << endl;
        cout << "Area: " << GetArea() << endl;
    }
};

int main() {
    Triangle triangle(2, 3, 4);
    triangle.ShowTriangle();
    return 0;
}
