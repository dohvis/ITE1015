#include <iostream>

using namespace std;

template<class T>
class MyContainer {
public:
    MyContainer() {
        obj_arr = nullptr;
        n_elements = 0;
    }

    MyContainer(size_t n) {
        obj_arr = new T[n];
        n_elements = n;
    }

    MyContainer(T *arr, size_t n) {
        obj_arr = arr;
        n_elements = n;
    }

    ~MyContainer() {

    }

    void clear() {
        for (T i : obj_arr) {
            delete i;
        }
        n_elements = 0;
    }

    virtual size_t size() {
        return n_elements;
    }

protected:
    T *obj_arr;
    size_t n_elements;
};

template<typename T>
void myswap(T &a, T &b) {
    T tmp;
    tmp = b;
    b = a;
    a = tmp;
}

