#include <iostream>
#include "class_template_inheritance.h"

using namespace std;

int main() {
    MyVector<int> myvec1;
    myvec1.push_back(0);
    cout << myvec1.size() << endl;//1
    cout << myvec1.max_size() << endl;//1

    int arr[] = {1, 2, 3, 4, 5};
    MyVector<int> myvec2(arr, 5);
    cout << myvec2.size() << endl;//5
    cout << myvec2.max_size() << endl;//5

    myvec2.push_back(5);
    cout << myvec2.size() << endl;//6
    cout << myvec2.max_size() << endl;//10

    for (int n = 0; n < myvec2.size(); n++)
        cout << myvec2[n] << " ";//1,2,3,4,5,5
    cout << endl;

    myvec2.back() = 6;
    for (int n = 0; n < myvec2.size(); n++)
        cout << myvec2.at(n) << " ";//1,2,3,4,5,6
    cout << endl;

    MyVector<int> myvec3 = myvec1 + myvec2;
    for (int n = 0; n < myvec3.size(); n++)
        cout << myvec3.at(n) << " ";//0,1,2,3,4,5,6
    cout << endl;

    return 1;
}
