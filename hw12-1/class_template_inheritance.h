#include <iostream>
#include "class_template.h"

template<class T>
class MyVector : public MyContainer<T> {
public:
    MyVector() : MyContainer<T>(0) {
        this->capacity = 0;
    }

    MyVector(T *arr, size_t n = 1) : MyContainer<T>(arr, n) {
        this->capacity = n;
    }

    ~MyVector() {
//        delete[] this->obj_arr;
    }


    bool empty() {
        return this->n_element == 0;
    }

    int size() {
        return MyContainer<T>::size();
    }

    int max_size() {
        return this->capacity;
    }

    void reserve(int new_cap) {
        this->capacity = new_cap;
        T *tmp = new T[this->capacity];
        for (int i = 0; i < this->n_elements; i++) {
            tmp[i] = this->obj_arr[i];
        }

        this->obj_arr = tmp;
    }

    void push_back(T obj) {
        if (this->capacity <= this->n_elements) {
            this->reserve(this->capacity == 0 ? 1 : this->capacity * 2);
        }
        this->obj_arr[this->n_elements] = obj;
        this->n_elements += 1;
    }

    void pop_back() {
        this->n_elements -= 1;
        this->obj_arr[this->n_elements] = NULL;
    }

    T &front() {
        return this->obj_arr[0];
    }

    T &back() {
        return this->obj_arr[this->n_elements - 1];
    }

    T &at(int idx) {
        return this->obj_arr[idx];
    }

    T &operator[](const int &i) {
        return this->obj_arr[i];
    }

    MyVector<T> operator+(MyVector<T> &rhs) {
        size_t new_vector_size = this->size() + rhs.size();
        T *new_obj_array = new int[new_vector_size];
        for (int i = 0; i < this->size(); i++) {
            new_obj_array[i] = this->at(i);
        }
        int idx = this->size();
        for (int i = 0; i < rhs.n_elements; i++) {
            new_obj_array[idx++] = rhs.at(i);
        }

        MyVector new_vec = MyVector<T>(new_obj_array, new_vector_size);
        return new_vec;
    }

private:
    int capacity;
};