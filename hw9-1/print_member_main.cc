#include <vector>
#include "print_member.h"

using namespace std;

int main() {
    vector<A *> objects;
    int ma;
    double mb;
    string mc;
    cin >> ma >> mb >> mc;
    A *a = new A(ma);
    B *b = new B(mb);
    C *c = new C(mc);
    objects.emplace_back(a);
    objects.emplace_back(b);
    objects.emplace_back(c);
    for (int i = 0; i < 3; i++) {
        objects[i]->print();
    }
    delete a;
    delete b;
    delete c;
    return 0;
}