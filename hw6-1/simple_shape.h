class Circle {
public:
    Circle(int x, int y, int r);
    double getArea();
    double getPerimeter();
private:
    int x;
    int y; // 중심
    int r;
};


class Rectangle {
public:
    Rectangle(int lx, int ly, int rx, int ry);
    double getArea();
    double getPerimeter();
private:
    int lx;
    int ly;
    int rx;
    int ry;
};
