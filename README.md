

lab3.cpp

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

class tPoint {
private:
    double x;
    double y;
    double dx;
    double dy;
public:
    tPoint() {
        x = rand() % 800;
        y = rand() % 600;
        dx = (rand() % 11 - 5) / 2.0;
        dy = (rand() % 11 - 5) / 2.0;
    }

    tPoint(double x0, double y0) {
        x = x0;
        y = y0;
        dx = (rand() % 11 - 5) / 2.0;
        dy = (rand() % 11 - 5) / 2.0;
    }

    void moveLinear() {
        x += dx;
        y += dy;
        if (x <= 0 || x >= 800) dx = -dx;
        if (y <= 0 || y >= 600) dy = -dy;
    }

    void moveRandom() {
        dx = (rand() % 11 - 5) / 2.0;
        dy = (rand() % 11 - 5) / 2.0;
        x += dx;
        y += dy;
        if (x <= 0) x = 0;
        if (x >= 800) x = 800;
        if (y <= 0) y = 0;
        if (y >= 600) y = 600;
    }

    void print() const {
        cout << "Point: (" << x << ", " << y << ")" << endl;
    }
};

int main() {
    srand(time(0));
    tPoint points[100];
    for (int i = 0; i < 100; i++) {
        points[i].print();
        points[i].moveLinear();
    }
    return 0;
}


⸻

lab4.cpp

#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>

using namespace std;

class Figure {
protected:
    double x, y;
public:
    Figure() {
        x = rand() % 500;
        y = rand() % 500;
    }
    Figure(double x0, double y0) {
        x = x0;
        y = y0;
    }
    void move(double dx, double dy) {
        x += dx;
        y += dy;
    }
};

class Line : public Figure {
protected:
    double x2, y2;
    double length;
public:
    Line() : Figure() {
        x2 = rand() % 500;
        y2 = rand() % 500;
        calculateLength();
    }
    Line(double x1, double y1, double x22, double y22) : Figure(x1, y1) {
        x2 = x22;
        y2 = y22;
        calculateLength();
    }
    void calculateLength() {
        length = sqrt((x2 - x)*(x2 - x) + (y2 - y)*(y2 - y));
    }
    void printLength() {
        cout << "Line length: " << length << endl;
    }
};

class Rectangle : public Figure {
protected:
    double width, height;
public:
    Rectangle() : Figure() {
        width = rand() % 100 + 1;
        height = rand() % 100 + 1;
    }
    Rectangle(double x0, double y0, double w, double h) : Figure(x0, y0) {
        width = w;
        height = h;
    }
    double perimeter() {
        return 2 * (width + height);
    }
    double area() {
        return width * height;
    }
};

class Square : public Rectangle {
public:
    Square() : Rectangle() {
        height = width;
    }
    Square(double x0, double y0, double s) : Rectangle(x0, y0, s, s) {}
};

int main() {
    srand(time(0));

    Line l1;
    Line l2(0,0,3,4);
    l1.printLength();
    l2.printLength();

    Square s1;
    Square s2(0,0,5);
    cout << s2.perimeter() << endl;
    cout << s2.area() << endl;

    Rectangle* arr = new Rectangle[3]{
        Rectangle(0,0,3,4),
        Rectangle(1,1,5,6),
        Rectangle(2,2,7,8)
    };

    for(int i=0;i<3;i++){
        cout << arr[i].perimeter() << " " << arr[i].area() << endl;
    }

    delete[] arr;

    return 0;
}


⸻

lab5.cpp

#include <iostream>
#include <cmath>
using namespace std;

class Figure {
public:
    virtual double perimeter() const = 0;
    virtual ~Figure() {}
};

class Rectangle : public Figure {
protected:
    double width, height;
    static int created;
    static int existing;
public:
    Rectangle() {
        width = 1;
        height = 1;
        created++;
        existing++;
    }
    Rectangle(double w, double h) {
        width = w;
        height = h;
        created++;
        existing++;
    }
    Rectangle(const Rectangle& r) {
        width = r.width;
        height = r.height;
        created++;
        existing++;
    }
    ~Rectangle() {
        existing--;
    }
    double perimeter() const override {
        return 2 * (width + height);
    }
    static void printCount() {
        cout << "Created: " << created << " Existing: " << existing << endl;
    }
};

int Rectangle::created = 0;
int Rectangle::existing = 0;

class Square : public Rectangle {
public:
    Square(double s) : Rectangle(s, s) {}
};

class Circle : public Figure {
    double r;
public:
    Circle(double r0) { r = r0; }
    double perimeter() const override {
        return 2 * 3.14159 * r;
    }
};

class Ellipse : public Figure {
    double a,b;
public:
    Ellipse(double a0,double b0){ a=a0;b=b0; }
    double perimeter() const override {
        return 3.14159*(3*(a+b)-sqrt((3*a+b)*(a+3*b)));
    }
};

int main() {
    Rectangle r1;
    Rectangle r2(3,4);
    Rectangle::printCount();

    Rectangle* pr = new Rectangle(5,6);
    Rectangle::printCount();

    Figure* arr[4];
    arr[0] = new Square(5);
    arr[1] = new Rectangle(2,3);
    arr[2] = new Circle(3);
    arr[3] = new Ellipse(4,2);

    Rectangle::printCount();

    for(int i=0;i<4;i++)
        cout << arr[i]->perimeter() << endl;

    for(int i=0;i<4;i++)
        delete arr[i];

    delete pr;

    Rectangle::printCount();

    return 0;
}