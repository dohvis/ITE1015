#include <iostream>
#include <sstream>
#include <string>
#include "sorted_array.h"

using namespace std;


int main() {
    string input;
    int num = 0;
    SortedArray *sa = new SortedArray();
    vector<int> tmp;
    do {
        cin >> input;

        if ((stringstream(input) >> num).fail()) {
            if (input == "ascend") {
                tmp = sa->GetSortedAscending();
                for (vector<int>::iterator it = tmp.begin(); it != tmp.end(); it++) {
                    cout << *it << " ";
                }
                cout << endl;
            } else if (input == "descend") {
                tmp = sa->GetSortedDescending();
                for (vector<int>::iterator it = tmp.begin(); it != tmp.end(); it++) {
                    cout << *it << " ";
                }
                cout << endl;
            } else if (input == "max") {
                cout << sa->GetMax() << endl;
            } else if (input == "min") {
                cout << sa->GetMin() << endl;
            }
        } else {
            sa->AddNumber(num);
        }
    } while (input != "quit");
    return 0;
}