#include <iostream>
#include "number.h"

using namespace std;


int main() {
    string mode;
    int value;
    Number *n = new Number();
    Square *s = new Square();
    Cube *c = new Cube();
    do {
        cin >> mode;
        if (mode == "number") {
            cin >> value;
            n->setNumber(value);
            cout << "getNumber(): " << n->getNumber() << endl;
        } else if (mode == "square") {
            cin >> value;
            s->setNumber(value);
            cout << "getNumber(): " << s->getNumber() << endl;
            cout << "getSquare(): " << s->getSquare() << endl;
        } else if (mode == "cube") {
            cin >> value;
            c->setNumber(value);
            cout << "getNumber(): " << c->getNumber() << endl;
            cout << "getSquare(): " << c->getSquare() << endl;
            cout << "getCube(): " << c->getCube() << endl;
        }
    } while (mode != "quit");
    return 0;
}