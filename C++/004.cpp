// 实验4.cpp : 设计CPPaga
//

#include "stdafx.h"
#include <iostream>
using namespace std;

// 矩形类
class Rectangle {
private:
    double length, width;
    int x, y, len;
    char *Str;
    static int count;
public:
    Rectangle() {
        length = 0;
        width = 0;
        x = 0;
        y = 0;
        Str = NULL;
        ++count;
    }

    Rectangle(double nl, double nw, int nx, int ny, const char *p) {
        length = nl;
        width = nw;
        x = nx;
        y = ny;
        len = strlen(p);
        Str = new char[len + 1];
        strcpy(Str, p);
        ++count;
    }

    Rectangle(int x1, int y1, int x2, int y2, const char *p) {
        length = abs(x1 - x2);
        width = abs(y1 - y2);
        x = x1;
        y = y1;
        len = strlen(p);
        Str = new char[len + 1];
        strcpy(Str, p);
        ++count;
    }

    Rectangle(Rectangle & r) {
        length = r.length;
        width = r.width;
        x = r.x;
        y = r.y;
        len = r.len;
        Str = r.Str;
        ++count;
    }

    ~Rectangle() {
        if (Str != NULL) {
            delete[] Str;
            Str = NULL;
        }
        --count;
    }

    void ShowRectangle();

    static int show() {
        return count;
    }

    friend class CPPage;
};

int Rectangle::count = 0;

void Rectangle::ShowRectangle() {
    cout << "length: " << length << endl;
    cout << "width: " << width << endl;
    cout << "the point: (" << x << ", " << y << ")" << endl;
    cout << "the text is : " << Str << endl;
    cout << endl;
}

// 圆形类
class Circle {
private:
    double radius;
    int X, Y, len2;
    char *Str2;
    static int count2;
public:
    Circle() {
        radius = 0;
        X = 0;
        Y = 0;
        Str2 = NULL;
        ++count2;
    }

    Circle(double R, int x, int y, const char *p2=0) {
        radius = R;
        X = x;
        Y = y;
        len2 = strlen(p2);
        Str2 = new char[len2 + 1];
        strcpy(Str2, p2);
        ++count2;
    }

    Circle(Circle & c) {
        radius = c.radius;
        X = c.X;
        Y = c.Y;
        len2 = c.len2;
        Str2 = c.Str2;
        ++count2;
    }

    ~Circle() {
        if (Str2 != NULL) {
            delete[]Str2;
            Str2 = NULL;
        }
        --count2;
    }

    void showCircle();

    static int show() {
        return count2;
    }
};

int Circle::count2 = 0;

void Circle::showCircle() {
    cout << "the center is: (" << X << ", " << Y << ")" << endl;
    cout << "the radius is: " << radius << endl;
    cout << "the text is: " << Str2 << endl;
    cout << endl;
}

// 组合类
class CPPage {
private:
    Rectangle rectangles;
    Circle circles;
public:
    CPPage(Rectangle &R, Circle &C) {
        rectangles = R;
        circles = C;
    }
    void showCPPage() {
        char *tStr;
        tStr = rectangles.Str;
        cout << "the text in the rectangle is: " << tStr << endl;
        rectangles.ShowRectangle();
        circles.showCircle();
    }
};


int main() {
    char s[] = "RECTANGLE";
    char s2[] = "CIRCLE";
    Rectangle *r = new Rectangle[3];
    Rectangle rectangle(3, 2, 1, 1, s);
    // Rectangle rectangle1(3.0, 3.0, 2, 2, s);
    // Rectangle rectangle2(rectangle);
    Rectangle rectangle3;
    rectangle.ShowRectangle();
    // rectangle1.ShowRectangle();
    // rectangle2.ShowRectangle();
    Circle *c  = new Circle[3];
    Circle circle(3.0, 1, 1, s2);
    // Circle circle1(2.0, 2, 2, s2);
    // Circle circle2(circle);
    circle.showCircle();
    // circle1.showCircle();
    // circle2.showCircle();
    CPPage cpPage(rectangle, circle);
    cpPage.showCPPage();
    cout << "the total number of rectangle is: " << Rectangle::show() << endl;
    cout << "the total number of circle is: " << Circle::show() << endl;
    delete [] r;
    delete [] c;
    system("pause");
    return 0;
}
