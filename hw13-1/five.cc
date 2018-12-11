#include <iostream>

using namespace std;

class A {

};

int main() {
    try {
        try {
            A a;
            throw a;
        }
        catch (A &a) {
#if 0//rethrow, 아래 throw twice구문도 실행시켜 볼  것
            cout << "rethrow" << endl;
            throw;
#else//throw twice
            cout << "throw twice" << endl;
                throw a;
#endif
        }
    }
    catch (A &a) {
        cout << "exception handled" << endl;
    }

    return 1;
}
