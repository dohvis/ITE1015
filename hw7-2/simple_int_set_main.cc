#include <iostream>
#include <regex>
#include <set>

#include "simple_int_set.h"

using namespace std;

int main() {
    char setOperator, token;
    do {
        set<int> setA = {}, setB = {}, resultSet = {};
        cin >> token;
        if (token == '0') {
            break;
        }

        if (token == '{') {
            InputSet(&setA);
        } else {
            continue;
        }
        cin >> setOperator;

        cin >> token;
        if (token == '{') {
            InputSet(&setB);
        } else {
            continue;
        }

        switch (setOperator) {
            case '+':
                resultSet = SetIntersection(setA, setB);
                break;
            case '*':
                resultSet = SetUnion(setA, setB);
                break;
            case '-':
                resultSet = SetDifference(setA, setB);
                break;
            default:
                break;
        }
        cout << "{ ";
        for (const int &element : resultSet) {
            cout << element << " ";
        }
        cout << "}" << endl;
    } while (true);
    return 0;
}