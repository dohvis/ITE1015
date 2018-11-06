
#include "message_book.h"

MessageBook::MessageBook() {

}

void MessageBook::AddMessage(int number, const string &message) {
    this->messages_[number] = message;
}

void MessageBook::DeleteMessage(int number) {
    for (auto it = this->messages_.cbegin(); it != this->messages_.end();) {
        if (it->first == number) {
            it = this->messages_.erase(it);
        } else {
            it++;
        }
    }
}

vector<int> MessageBook::GetNumbers() const {
    vector<int> result;
    for (map<int, string>::const_iterator it = this->messages_.cbegin(); it != this->messages_.end(); it++) {
        result.emplace(result.end(), it->first);
    }
    return result;
}

const string &MessageBook::GetMessage(int number) const {
    auto it = this->messages_.find(number);
    if (it == this -> messages_.end()) {
        return "";
    }
    return this->messages_.find(number)->second;
}
