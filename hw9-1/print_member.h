#include <iostream>

using namespace std;

class A {
public:
    A() {

    }

    A(int a) {
        cout << "new memberA" << endl;
        this->memberA = new int(a);
    }

    ~A() {
        delete memberA;
        cout << "delete memberA" << endl;
    }

    virtual void print() {
        cout << "*memberA " << *this->memberA << endl;
    }

private:
    int *memberA;
};

class B : public A {
public:
    B(double b) : A(1) {
        cout << "new memberB" << endl;
        this->memberB = new double(b);
    }

    ~B() {
        delete memberB;
        cout << "delete memberB" << endl;
    }

    virtual void print() {
        A::print();
        cout << "*memberB " << *this->memberB << endl;
    }

private:
    double *memberB;
};

class C : public B {
public:
    C(string c) : B(1.1) {
        cout << "new memberC" << endl;
        this->memberC = new string(c);
    }

    ~C() {
        delete memberC;
        cout << "delete memberC" << endl;
    }

    virtual void print() {
        B::print();
        cout << "*memberC " << *this->memberC << endl;
    }

private:
    string *memberC;
};
