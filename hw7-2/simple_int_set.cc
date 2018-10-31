#include <sstream>
#include "simple_int_set.h"

set<int> SetIntersection(const set<int> &set0, const set<int> &set1) {
    set<int> result;
    result = set0;
    for (const int &element : set1) {
        if (set0.count(element) == 0) {
            result.insert(element);
        }
    }
    return result;
}

set<int> SetUnion(const set<int> &set0, const set<int> &set1) {
    set<int> result;
    for (const int &set1Element : set1) {
        if (set0.count(set1Element) > 0) {
            result.insert(set1Element);
        }
    }

    return result;
}

set<int> SetDifference(const set<int> &set0, const set<int> &set1) {
    set<int> result;
    result = set0;
    for (const int &element : set1) {
        if (set0.count(element) != 0) {
            result.erase(result.find(element));
        }
    }
    return result;
}

bool InputSet(set<int> *s) {
    string input;
    int num;
    do {
        cin >> input;
        if ((stringstream(input) >> num).fail()) {
            break;
        }
        s->insert(num);
    } while (input != "}");
    return true;
}
