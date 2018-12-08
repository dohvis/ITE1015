#include <iostream>

using namespace std;

template<class T>
class Node {
public:
    T data;
    Node<T> *next;
};

template<class T>
class List {
private:
    Node<T> *head;
public:
    List() : head(NULL) {};

    ~List() {
        // Do nothing
    }

    List(T *arr, int n_nodes) {
        head = new Node<T>();
        Node<T> *tmp = head;
        Node<T> *prev = tmp;
        for (int i = 0; i < n_nodes; i++) {
            tmp->data = arr[i];
            tmp->next = new Node<T>();
            prev = tmp;
            tmp = tmp->next;
        }
        prev->next = nullptr;
        delete tmp;
    }//create a list with n_nodes
    //List &operator=(const List &rhs);//assignment operation
    void insert_at(int idx, T data) {
        Node<T> *cur = head;
        for (int i = 0; i < idx - 1; i++) {
            cur = cur->next;
        }
        Node<T> *tmp = new Node<T>();
        tmp->data = data;
        tmp->next = cur->next;
        cur->next = tmp;
    }

    void remove_at(int idx) {
        Node<T> *cur = head;
        Node<T> *prev = cur;
        for (int i = 0; i < idx; i++) {
            prev = cur;
            cur = cur->next;
        }
        prev->next = cur->next;
        delete cur;
    }

    void pop_back() {
        Node<T> *tmp = head;
        Node<T> *prev = tmp;
        while (tmp->next != nullptr) {
            prev = tmp;
            tmp = tmp->next;
        }
        delete tmp;
        prev->next = nullptr;
    }

    void push_back(T val) {
        Node<T> *tmp = head;
        while (tmp->next != nullptr) {
            tmp = tmp->next;
        }
        tmp->next = new Node<T>();
        tmp->next->next = nullptr;
        tmp->next->data = val;
    }

    void pop_front() {
        Node<T> *tmp = head;
        head = head->next;
        delete tmp;
    }

    void push_front(T val) {
        Node<T> *tmp = new Node<T>();
        tmp->data = val;
        tmp->next = head;
        head = tmp;
    }

    friend ostream &operator<<(ostream &out, List &rhs) {
        Node<T> *tmp = rhs.head;
        while (tmp != nullptr) {
            out << tmp->data;
            out << " ";
            tmp = tmp->next;
        }
        out << endl;
        return out;
    }//리스트 내 노드값 출력
};
