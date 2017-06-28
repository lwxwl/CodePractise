#include "stdafx.h"
#include <iostream>
using namespace std;

class Graph
{
private:
    int type;
    int color;
    int linewide;
public:
    Graph() {
        type = 0;
        color = 0;
        linewide = 0;
    }
    Graph(int type, int color, int linewide) {
        this->type = type;
        this->color = color;
        this->linewide = linewide;
    }
    void show() {
        cout << "type: " << type << " color: " << color << " linewide: " << linewide << endl;
    }
};

class Rectangle: virtual public Graph
{
private:
    double length, width;
    int x, y, len;
    char *Str;
    static int count;
public:
    Rectangle() : Graph()
    {
        length = 0;
        width = 0;
        x = 0;
        y = 0;
        Str = NULL;
        ++count;
    }
    Rectangle(int type, int color, int linewide, double length, double width, int nx, int ny, const char *p) : Graph(type, color, linewide)
    {
        this->length = length;
        this->width = width;
        x = nx;
		y = ny;
        len = strlen(p);
        Str = new char[len + 1];
        strcpy(Str, p);
        ++count;
    }
    
    ~Rectangle() {
        if (Str != NULL) {
            delete[] Str;
            Str = NULL;
        }
        --count;
    }
    
    void show();
    
    static int showCount() {
        return count;
    }
    
    friend class CPPage;
};

int Rectangle::count = 0;

void Rectangle::show() {
    cout << "rectangle: ";
    Graph::show();
    cout << "length: " << length << " width: " << width << endl;
    cout << "the point: (" << x << ", " << y << ")" << endl;
    cout << "the text is : " << Str << endl;
    cout << endl;
}

class Circle : virtual public Graph
{
private:
    double radius;
    int X, Y, len2;
    char *Str2;
    static int count2;
public:
    Circle() :Graph()
    {
        radius = 0;
        X = 0;
        Y = 0;
        Str2 = NULL;
        ++count2;
    }
    Circle(int type, int color, int linewide, double radius, int x, int y, const char *p2 = 0) : Graph(type, color, linewide)
    {
        this->radius = radius;
        X = x;
        Y = y;
        len2 = strlen(p2);
        Str2 = new char[len2 + 1];
        strcpy(Str2, p2);
        ++count2;
    }
    
    ~Circle() {
        if (Str2 != NULL) {
            delete[]Str2;
            Str2 = NULL;
        }
        --count2;
    }
    
    void show();
    
    static int showCount() {
        return count2;
    }
};

int Circle::count2 = 0;

void Circle::show() {
    cout << "circle: ";
    Graph::show();
    cout << "the center is: (" << X << ", " << Y << ")" << endl;
    cout << "the radius is: " << radius << endl;
    cout << "the text is: " << Str2 << endl;
}

class CCircleRect: public Rectangle, public Circle
{
public:
    CCircleRect() : Graph(), Rectangle(), Circle() {}
    
    CCircleRect(int rtype, int rcolor, int rlinewide, double length, double width, int x, int y, const char *p,
                int ctype, int ccolor, int clinewide, double radius, int X, int Y, const char *p2 = 0):
    Graph(rtype, rcolor, rlinewide),
    Rectangle(rtype, rcolor, rlinewide, length, width, x, y, p),
    Circle(ctype, ccolor, clinewide, radius, X, Y, p2) {}
    
    ~CCircleRect() {}
    
    void show();
};

void CCircleRect::show() {
    cout << "------------------------------------------" << endl;
    cout << "CircleRect: " << endl;
    Rectangle::show();
    Circle::show();
    cout << "------------------------------------------" << endl;
}


class CPPage {
private:
    Rectangle rectangles;
    Circle circles;
    CCircleRect circleRects;
public:
    CPPage(Rectangle &R, Circle &C, CCircleRect &CR) {
        rectangles = R;
        circles = C;
        circleRects = CR;
    }
    void showCPPage() {
        //char *tStr;
        //tStr = rectangles.Str;
        //cout << "the text in the rectangle is: " << tStr << endl;
        cout << "CPPage: " << endl;
        cout << "------------------------------------------" << endl;
        rectangles.show();
        cout << "------------------------------------------" << endl;
        circles.show();
        circleRects.show();
        cout << "the total number of rectangle is: " << Rectangle::showCount() << endl;
        cout << "the total number of circle is: " << Circle::showCount() << endl;
    }
};

int main() {
    char s[] = "RECTANGLE";
    char s2[] = "CIRCLE";
    Rectangle rectangle(0, 0, 0, 1.0, 1.0, 0, 0, s);
    //rectangle.show();
    Circle circle(1, 1, 1, 3.0, 0, 0, s2);
    //circle.show();
    CCircleRect circleRect(0, 0, 0, 1.0, 1.0, 0, 0, s, 1, 1, 1, 3.0, 0, 0, s2);
    circleRect.show();
    CPPage cpPage(rectangle, circle, circleRect);
    cpPage.showCPPage();
    system("pause");
    return 0;
}
