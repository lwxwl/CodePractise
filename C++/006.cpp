#include <iostream>
using namespace std;
int num1 = 0;
int num2 = 0;
int num3 = 0;

class Graph
{
protected:
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
    virtual ~Graph() {}
    virtual void ShowMsg() = 0;
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
    }

    void ShowMsg() {
        cout << "rectangle: ";
        cout << "type: " << type << " color: " << color << " linewide: " << linewide << endl;
        cout << "length: " << length << " width: " << width << endl;
        cout << "the point: (" << x << ", " << y << ")" << endl;
        cout << "the text is : " << Str << endl;
        cout << endl;
    }

    static int showCount() {
        return (count-num3);
    }

    friend class CPPage;
};

int Rectangle::count = 0;


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
    }

    void ShowMsg() {
        cout << "circle: ";
        cout << "type: " << type << " color: " << color << " linewide: " << linewide << endl;
        cout << "the center is: (" << X << ", " << Y << ")" << endl;
        cout << "the radius is: " << radius << endl;
        cout << "the text is: " << Str2 << endl;
    }

    static int showCount() {
        return (count2-num3);
    }
};

int Circle::count2 = 0;

class CCircleRect: public Rectangle, public Circle
{
public:
    CCircleRect() : Graph(), Rectangle(), Circle() {}

    CCircleRect(int rtype, int rcolor, int rlinewide, double length, double width, int x, int y, const char *p,
                double radius, int X, int Y, const char *p2 = 0):
            Graph(rtype, rcolor, rlinewide),
            Rectangle(rtype, rcolor, rlinewide, length, width, x, y, p),
            Circle(rtype, rcolor, rlinewide, radius, X, Y, p2) {}

    ~CCircleRect() {}

    void ShowMsg() {
        cout << "------------------------------------------" << endl;
        cout << "CircleRect: " << endl;
        Rectangle::ShowMsg();
        Circle::ShowMsg();
        cout << "------------------------------------------" << endl;
    };
};

class CPPage {
private:
    Graph * graph[100];
public:
    CPPage () {
        cout << "CPPage: " << endl;
        cout << "------------------------------------------" << endl;
    }

    ~CPPage() {};

    void createRect() {
        double length, width;
        char text1[100] = {0};
        int num_rect, type, color, linewide, rx, ry;
        cout << "Please input the amount of rectangles: " << endl;
        cin >> num_rect;
        num1 = num_rect;
        for (int i = 0; i < num_rect; i++) {
            cout << "Please enter the following data in turn" << endl;
            cout << "type - color - linewide - length - width - Point x - Point y - text" << endl;
            cin >> type >> color >> linewide >> length >> width >> rx >> ry >> text1;
            graph[i] = new Rectangle(type, color, linewide, length, width, rx, ry, text1);
        }
    }

    void createCircle() {
        double radius;
        char text2[100] = {0};
        int num_circle, type, color, linewide, cx, cy;
        cout << "Please input the amount of circles: " << endl;
        cin >> num_circle;
        num2 = num_circle;
        for (int j = num1; j < (num_circle + num1); j++) {
            cout << "Please enter the following data in turn" << endl;
            cout << "type - color - linewide - radius - Point x - Point y - text" << endl;
            cin >> type >> color >> linewide >> radius >> cx >> cy >> text2;
            graph[j] = new Circle(type, color, linewide, radius, cx, cy, text2);
        }
    }

    void createCircleRect() {
        double length, width, radius;
        int type, color, linewide, rx, ry, cx, cy, num_circleRect;
        char text1[100] = {0};
        char text2[100] = {0};
        cout << "Please input the amount of circleRects: " << endl;
        cin >> num_circleRect;
        num3 = num_circleRect;
        for (int k = num1 + num2; k < num1 + num2 + num3; k++) {
            cout << "Please enter the following data in turn" << endl;
            cout << "type - color - linewide - length- width - Point X - Point Y - text1 - "
                    "radius - Point x - Point y - text2" << endl;
            cin >> type >> color >> linewide >> length >> width >> rx >> ry
                >> text1 >> radius >> cx >> cy >> text2;
            graph[k] = new CCircleRect(type, color, linewide, length, width, rx, ry, text1, radius, cx, cy, text2);
        }
    }

    void showCPPage() {
        for (int i = 0; i < (num1 + num2 + num3); i++) {
            graph[i]->ShowMsg();
            delete graph[i];
        }
        cout << "------------------------------------------" << endl;
        cout << "the total number of rectangle is: " << Rectangle::showCount() << endl;
        cout << "the total number of circle is: " << Circle::showCount() << endl;
        cout << "the total number of circleRect is: " << num3 << endl;;
    }
};

int main() {
    CPPage cpPage;
    cpPage.createRect();
    cpPage.createCircle();
    cpPage.createCircleRect();
    cpPage.showCPPage();
    return 0;
}
