#include <iostream>

using namespace std;

class A {
public:
    A(int n) {
        if (n <= 0) {
            throw n;
        }
        cout << "ID=" << n << ": constructed\n";
        n_ID = n;
        data = new int[n];
    }

    ~A() {
        cout << "ID=" << n_ID << ": destroyed\n";
        delete this->data;
    }

private:
    int *data = nullptr;
    int n_ID;
};

int main() {
    try {
        A a(3);
        A b(2);
        {
            A c(1);
            A d(0);
            A e(-1);
        }
    } catch (int &e) {
        cout << "caught in the main" << endl;
    }
    return 1;
}

