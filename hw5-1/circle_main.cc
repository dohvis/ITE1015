#include <iostream>
#include "circle.h"

using namespace std;

int main() {
    double r;
    cin >> r;
    double perimeter = getCirclePerimeter(r);
    double area = getCircleArea(r);
    cout << "Perimeter: " << perimeter << endl;
    cout << "Area: " << area << endl;
    return 0;
}
