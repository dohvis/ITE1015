#include <iostream>
#include "simple_shape.h"

using namespace std;

int main() {
    char type;

    do {
        cout << "shape?" << endl;
        cin >> type;
        if (type == 'C') {
            int x, y, r;
            cin >> x >> y >> r;
            Circle *c = new Circle(x, y, r);
            cout << "area: " << c->getArea() << ", perimeter: " << c->getPerimeter() << endl;
        } else if (type == 'R') {
            int lx, ly, rx, ry;
            cin >> lx >> ly >> rx >> ry;
            Rectangle *r = new Rectangle(lx, ly, rx, ry);
            cout << "area: " << r->getArea() << ", perimeter: " << r->getPerimeter() << endl;
        }
    } while (type != 'Q');
    return 0;
}
