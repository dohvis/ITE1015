#include <iostream>
#include "draw_shape.h"

using namespace std;

int main() {
    int width, height;
    cin >> width >> height;
    string mode;

    do {
        cin >> mode;
        if (mode == "rect") {
            int x, y;
            char brush;
            cin >> x >> y >> height >> width >> brush;
            Rect *shape = new Rect();

        } else if (mode == "diamond") {
            int x, y;
            Diamond *shape = new Diamond();
        } else if (mode == "square") {
            int x, y;
            char brush;
            cin >> x >> y >> width >> brush;
            Square *shape = new Square();
        } else {
            Shape *shape = new Shape();
        }
        auto shape = shape;
        cout << "Area: " << shape.GetArea() << endl;
        cout << "Perimeter: " << shape.GetPErimeter << endl;
        shape.Draw();
    } while (mode != "quit");
    return 0;
}
