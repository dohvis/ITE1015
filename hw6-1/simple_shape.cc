#include "simple_shape.h"
#include <cmath>

using namespace std;

Circle::Circle(int x, int y, int r){
    this->x = x;
    this->y = y;
    this->r = r;
};

double Circle::getArea() {
    return 3.14 * this->r * this->r;
}

double Circle::getPerimeter(){
    return 2 * this->r * 3.14;
}

Rectangle::Rectangle(int lx, int ly, int rx, int ry) {
    this->lx = lx;
    this->ly = ly;
    this->rx = rx;
    this->ry = ry;
}

double Rectangle::getArea() {
    double x = this->lx - this->rx;
    double y = this->ly - this->ry;
    return abs(x) * abs(y);
}

double Rectangle::getPerimeter(){
    double x = this->lx - this->rx;
    double y = this->ly - this->ry;
    return 2 * (abs(x)+abs(y));
}