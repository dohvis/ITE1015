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
    for (vector<A *>::const_iterator it = objects.begin(); it != objects.end(); it++) {
        (*it)->print();
    }
    delete a;
    delete b;
    delete c;
    return 0;
}