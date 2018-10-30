#include <iostream>
#include "integer_set.h"

using namespace std;

void printVectors(vector<int>& vectors) {
    for (vector<int>::iterator it = vectors.begin(); it != vectors.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}
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
            printVectors(tmp);
        } else if (cmd == "del") {
            cin >> value;
            is->DeleteNumber(value);
            tmp = is->GetAll();
            printVectors(tmp);
        } else if (cmd == "get") {
            cin >> value;
            cout << is->GetItem(value) << endl;
        }
    } while (cmd != "quit");
    return 0;
}
