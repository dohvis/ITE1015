#include <algorithm>
#include <iostream>
#include "sorted_array.h"

using namespace std;

SortedArray::SortedArray() {
}

void SortedArray::AddNumber(const int num) {
    this->numbers_.emplace_back(num);
}

bool ascend(int i, int j) { return i < j; }
bool descend(int i, int j) { return i > j; }

vector<int> SortedArray::GetSortedAscending() const {
    vector<int> tmp;
    tmp.reserve(this->numbers_.size());
    for(int i=0;i<this->numbers_.size(); i++ ) {
        tmp.push_back(this->numbers_[i]);
    }
    sort(tmp.begin(), tmp.end(), ascend);
    return tmp;
}

vector<int> SortedArray::GetSortedDescending() const {
    vector<int> tmp;
    tmp.reserve(this->numbers_.size());
    for(int i=0;i<this->numbers_.size(); i++ ) {
        tmp.push_back(this->numbers_[i]);
    }
    sort(tmp.begin(), tmp.end(), descend);
    return tmp;
}

int SortedArray::GetMax() const {
  return this->GetSortedDescending()[0];
};
int SortedArray::GetMin() const {
    return this->GetSortedAscending()[0];
};
