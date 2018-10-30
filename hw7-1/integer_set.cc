#include <algorithm>
#include "integer_set.h"

IntegerSet::IntegerSet() {

}

bool ascend(int i, int j) { return i < j; }


void IntegerSet::AddNumber(const int num) {
    if (!std::binary_search(this->numbers_.begin(), this->numbers_.end(), num)) {
        this->numbers_.emplace_back(num);
        sort(this->numbers_.begin(), this->numbers_.end(), ascend);
    }
}

void IntegerSet::DeleteNumber(const int num) {
    for (vector<int>::iterator it = this->numbers_.begin(); it != this->numbers_.end(); it++) {
        if (*it == num) {
            this->numbers_.erase(it);
        }
    }
}

int IntegerSet::GetItem(int pos) const {
    if (pos >= this->numbers_.size()) {
        return -1;
    }
    return this->numbers_[pos];
}

std::vector<int> IntegerSet::GetAll() const {
    return this->numbers_;
}