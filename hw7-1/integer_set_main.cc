#include <iostream>
#include "integer_set.h"

using namespace std;

int main() {
    string cmd;
    int value;
    IntegerSet *is = new IntegerSet();
    vector<int> tmp;
    do {
        cin >> cmd;
        if (cmd == "add") {
            cin >> value;
            is->AddNumber(value);
            tmp = is->GetAll();
            for (vector<int>::iterator it = tmp.begin(); it != tmp.end(); it++) {
                std::cout << *it << " ";
            }
            std::cout << std::endl;
        } else if (cmd == "del") {
            cin >> value;
            is->DeleteNumber(value);
            tmp = is->GetAll();
            for (vector<int>::iterator it = tmp.begin(); it != tmp.end(); it++) {
                std::cout << *it << " ";
            }
            std::cout << std::endl;
        } else if (cmd == "get") {
            cin >> value;
            cout << is->GetItem(value) << endl;
        }
    } while (cmd != "quit");
    return 0;
}
