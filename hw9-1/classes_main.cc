#include <vector>
#include "classes.h"

using namespace std;

int main() {
    vector<A *> objects;
    A *a = new A();
    B *b = new B();
    C *c = new C();
    objects.emplace_back(a);
    objects.emplace_back(b);
    objects.emplace_back(c);
    for (int i = 0; i < 3; i++) {
        objects[i]->test();
    }
    delete a;
    delete b;
    delete c;
    return 0;
}