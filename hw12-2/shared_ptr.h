#include <iostream>

using namespace std;

template<typename T>
class My_shared_ptr {
private:
    T *m_obj;
    int *count;
public:
    My_shared_ptr() {
        m_obj = nullptr;
        count = nullptr;
    }

    My_shared_ptr(T *obj) {
        m_obj = obj;
        count = new int(1);
    }

    My_shared_ptr(My_shared_ptr const &rhs) {
        m_obj = rhs.m_obj;
        count = rhs.m_count;
        *count += 1;
        cout << "My_shared_ptr";
    }

    ~My_shared_ptr() {
        *count -= 1;
        if (*count <= 0) {
            delete m_obj;
            delete count;

            cout << "Everything destroyed" << endl;
        }
    }

    My_shared_ptr &operator=(My_shared_ptr const &rhs) {
        if (m_obj == nullptr && count == nullptr) {
            delete m_obj;
            delete count;
        } else {
            *count -= 1;
            if (*count <= 0) {
                delete m_obj;
                delete count;
            }
        }

        m_obj = rhs.m_obj;
        count = rhs.count;
        *count += 1;

        return *this;
    }

    const T *get_m_obj() {
        return m_obj;
    }

    int getCount() {
        if (count != nullptr) {
            return *count;
        } else {
            return 0;
        }
    }

    void increase() {}

    void decrease() {}
};