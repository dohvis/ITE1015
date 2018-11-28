#include "MyVector.h"

MyVector::MyVector(int arraySize) {
    this->array = new int[arraySize];
    currentIndex = 0;
}

MyVector::~MyVector() {
    delete[] array;
}


void MyVector::append(const int number) {
    array[currentIndex] = number;
    currentIndex += 1;
}

void MyVector::operator+=(const int addedValue) {
    for (int i = 0; i < currentIndex; i++) {
        array[i] += addedValue;
    }
}

void MyVector::operator+=(const MyVector &mv) {
    for (int i = 0; i < currentIndex; i++) {
        this->array[i] += mv.array[i];
    }
}

void MyVector::operator-=(const int addedValue) {
    for (int i = 0; i < currentIndex; i++) {
        array[i] -= addedValue;
    }
}

void MyVector::operator-=(const MyVector &mv) {
    for (int i = 0; i < currentIndex; i++) {
        this->array[i] -= mv.array[i];
    }
}



//
//friend istream &operator>>(istream &in, MyVector b);
//};
