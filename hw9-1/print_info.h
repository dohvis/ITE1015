#include <iostream>

using namespace std;

class A {
public:
    virtual string getTypeInfo() {
        return "This is an instance of class A";
    }
};

class B : public A {
public:
    virtual string getTypeInfo() {
        return "This is an instance of class B";
    }
};

class C : public B {
public:
    virtual string getTypeInfo() {
        return "This is an instance of class C";
    }
};


void printObjectTypeInfo1(A *object) {
    cout << object->getTypeInfo() << endl;
}

void printObjectTypeInfo2(A &object) {
    cout << object.getTypeInfo() << endl;

}
