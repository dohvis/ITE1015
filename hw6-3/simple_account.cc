#include <stdio.h>
#include "simple_account.h"

#define MAX_BALANCE 1000000


User::User(int id) {
    this->id = id;
    this->balance = 0;
}

bool User::deposit(int inputAmount) {
    if (this->balance + inputAmount > MAX_BALANCE) {
        return false;
    }
    this->balance += inputAmount;
    return true;
}

bool User::withDraw(int inputAmount) {
    if (this->balance - inputAmount < 0) {
        return false;
    }
    this->balance -= inputAmount;
    return true;
}

bool User::transfer(User *to, int inputAmount) {
    return this->withDraw(inputAmount) && to->deposit(inputAmount);
}

void User::printBalance() {
    printf("Balance of user %d: %d\n", this->id, this->balance);
}
