#include <iostream>
#include "draw_shape.h"

using namespace std;

int main() {
    int canvasWidth, canvasHeight;
    cin >> canvasWidth >> canvasHeight;
    string mode;
    int width, height, x, y;
    char brush;
    do {
        cin >> mode;
        if (mode == "rect") {
            cin >> x >> y >> height >> width >> brush;
            Rect *rect = new Rect(x, y, brush, width, height);
            cout << "Area: " << rect->GetArea() << endl;
            cout << "Perimeter: " << rect->GetPerimeter() << endl;
            rect->Draw(canvasWidth, canvasHeight);
        } else if (mode == "diamond") {
            int distance;
            cin >> x >> y >> distance >> brush;
            Diamond *diamond = new Diamond(x, y, distance, brush);
            cout << "Area: " << diamond->GetArea() << endl;
            cout << "Perimeter: " << diamond->GetPerimeter() << endl;
            diamond->Draw(canvasWidth, canvasHeight);
        } else if (mode == "square") {
            cin >> x >> y >> width >> brush;
            Square *square = new Square(x, y, brush, width, width);
            cout << "Area: " << square->GetArea() << endl;
            cout << "Perimeter: " << square->GetPerimeter() << endl;
            square->Draw(canvasWidth, canvasHeight);
        } else {
        }
        cin.ignore();
    } while (mode != "quit");
    return 0;
}
