#include <iostream>

using namespace std;

class MyVector {
private:

public:
    int *array;
    int currentIndex;

    MyVector(int arraySize);

    ~MyVector();

    void append(const int number);

    void operator+=(const MyVector &mv);

    void operator+=(const int number);

    void operator-=(const MyVector &mv);

    void operator-=(const int number);


    friend ostream &operator<<(ostream &out, MyVector &b) {
        for (int i = 0; i < b.currentIndex; i++) {
            out << b.array[i] << " ";
        }
        out << endl;
        return out;
    }

//    friend istream &operator>>(istream &in, MyVector b);
};
