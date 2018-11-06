#include <iostream>
#include <stdio.h>
#include "rectangle.h"

using namespace std;


int main() {
    string mode;
    int width, height;

    do {
        cin >> mode;
        if (mode == "nonsquare") {
            cin >> width >> height;
            NonSquare *ns = new NonSquare(width, height);
            ns->print();
        } else if (mode == "square") {
            cin >> width;
            Square *s = new Square(width);
            s->print();
        }
    } while (mode != "quit");
    return 0;
}