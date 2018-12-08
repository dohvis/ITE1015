#include "linked_list.h"

int main() {
    int array[5] = {12, 7, 9, 21, 13};
    List<int> li(array, 5);
    cout << li; //12,7,9,21,13

    li.pop_back();
    cout << li; //12,7,9,21

    li.push_back(15);
    cout << li; //12,7,9,21,15

    li.pop_front();
    cout << li; //7,9,21,15

    li.push_front(8);
    cout << li; //8,7,9,21,15

    li.insert_at(4, 19);
    cout << li; //8,7,9,21,19,15

    li.remove_at(1);
    cout << li; //8,9,21,19,15

    return 1;
}