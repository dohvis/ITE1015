#include <iostream>
#include <vector>
#include "class_function.h"

using namespace std;

int main() {
    string input;
    vector<A *> objects;
    do {
        cin >> input;
        if (input == "B") {
            B *b = new B();
            objects.emplace_back(b);
        } else if (input == "C") {
            C *c = new C();
            objects.emplace_back(c);
        } else if (input == "BB") {
            BB *bb = new BB();
            objects.emplace_back(bb);
        }
    } while (input != "0");
    for (auto &obj : objects) {
        obj->test1();
        obj->test2();
        delete obj;
    }
    return 0;
}