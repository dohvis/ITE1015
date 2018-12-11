#include <iostream>

using namespace std;

class A {
public:
    A() {
        throw string("constructor");
    }

    ~A() {
        cout << "destructor?" << endl;
        throw string("destructor");
    }
};

int main() {
    try {
        A a = A();
    } catch (string &str) {
        cout << str;
    }
    return 0;
}
