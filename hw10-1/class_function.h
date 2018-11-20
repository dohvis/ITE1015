/*
 * A라는 클래스를 작성하고, public member function으로 test1()과 test2()함수를 작성한다. A::test1()함수는 “A::test1()”라는 문자열을 출력해야 하며,
 * A::test2()는 순수 가상 함수(pure virtual function)이다.
A를 상속받는 B라는 클래스는 “B::test2()”라는 문자열을 출력하도록 test2() 함수를 구현한다.
A를 상속받는 C라는 클래스는 “C::test1()”라는 문자열을 출력하는 test1()함수와 “C::test2()”를 출력하는 test2() 함수를 가진다.
B를 상속받는 BB라는 클래스는 “BB:test1()”라는 문자열을 출력하는 test1() 함수를 가진다.
 */
#include <iostream>

using namespace std;

class A {
public:
    virtual void test1() {
        cout << "A::test1()" << endl;
    }

    virtual void test2() = 0;
};

class B : public A {
public:
    void test2() {
        cout << "B::test2()" << endl;
    }
};

class C : public A {
public:
    void test1() {
        cout << "C::test1()" << endl;
    }

    void test2() {
        cout << "C::test2()" << endl;
    }
};

class BB : public B {
public:
    void test1() {
        cout << "BB:test1()" << endl;
    }
};
