#include <iostream>
using namespace std;

class Rectangle {
private:
    double length, width;
    int x, y, len;
    char *Str;
public:
    Rectangle() {
        length = 0;
        width = 0;
        x = 0;
        y = 0;
        Str = NULL;
    }

    Rectangle(double nl, double nw, int nx, int ny, const char *p) {
        length = nl;
        width = nw;
        x = nx;
        y = ny;
        len = strlen(p);
        Str = new char[len + 1];
        strcpy(Str, p);
    }

    Rectangle(int x1, int y1, int x2, int y2, const char *p) {
        length = abs(x1 - x2);
        width = abs(y1 - y2);
        x = x1;
        y = y1;
        len = strlen(p);
        Str = new char[len + 1];
        strcpy(Str, p);
    }

    Rectangle(Rectangle & r) {
        length = r.length;
        width = r.width;
        x = r.x;
        y = r.y;
        len = r.len;
        Str = r.Str;
    }

    ~Rectangle() {
        if (Str != NULL) {
            delete[] Str;
            Str = NULL;
        }
    }
    void ShowRectangle();
};

void Rectangle::ShowRectangle() {
    cout << "length: " << length << endl;
    cout << "width: " << width << endl;
    cout << "the point: (" << x << ", " << y << ")" << endl;
    cout << "the text is : " << Str << endl;
    cout << endl;
}

int main() {
    char s[] = "RECTANGLE";
    Rectangle rectangle(3, 2, 1, 1, s);
    Rectangle rectangle1(3.0, 3.0, 2, 2, s);
    Rectangle rectangle2(rectangle);
    rectangle.ShowRectangle();
    rectangle1.ShowRectangle();
    rectangle2.ShowRectangle();
    return 0;
}
