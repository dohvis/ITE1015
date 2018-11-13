class A {
public:
    virtual void test();
};

class B : public A {
public:
    virtual void test();
};

class C : public B {
public:
    virtual void test();
};
