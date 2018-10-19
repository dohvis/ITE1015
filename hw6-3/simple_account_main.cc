#include <stdio.h>
#include <iostream>

#include "simple_account.h"

using namespace std;

int userCnt = 0, currentUserID = 0;
int inputAmount = 0;
User *users[10];

void createUser() {
    if (userCnt > 9) {
        printf("Can't create user\n");
        printf("Max user count: 10, current user count: %d \n", userCnt);
        return;
    }
    User *newUser = new User(userCnt);
    users[userCnt] = newUser;
    userCnt += 1;
    printf("Account for user %d registered\n", newUser->id);
    newUser->printBalance();
}

void deposit() {
    cin >> currentUserID >> inputAmount;
    if (currentUserID >= userCnt) {
        printf("Account does not exist\n");
        return;
    }
    bool isSuccess = users[currentUserID]->deposit(inputAmount);
    if (isSuccess) {
        printf("Success: Deposit to user %d: %d\n", currentUserID, inputAmount);
        users[currentUserID]->printBalance();
    } else {
        printf("Failure: Deposit from user %d: %d\n", currentUserID, inputAmount);
        users[currentUserID]->printBalance();
    }
}

void withDraw() {
    cin >> currentUserID >> inputAmount;
    if (currentUserID >= userCnt) {
        printf("Account does not exist\n");
        return;
    }
    bool isSuccess = users[currentUserID]->withDraw(inputAmount);
    if (isSuccess) {
        printf("Success: Withdraw to user %d: %d\n", currentUserID, inputAmount);
        users[currentUserID]->printBalance();
    } else {
        printf("Failure: Withdraw from user %d: %d\n", currentUserID, inputAmount);
        users[currentUserID]->printBalance();
    }
}

void transfer() {
    int toWhom;
    cin >> currentUserID >> toWhom >> inputAmount;
    if (currentUserID >= userCnt or toWhom >= userCnt) {
        printf("Account does not exist\n");
        return;
    }
    User *to = users[toWhom];
    bool isSuccess = users[currentUserID]->transfer(to, inputAmount);
    if (isSuccess) {
        printf("Success: Transfer from user %d to user %d %d\n", currentUserID, toWhom, inputAmount);
        users[currentUserID]->printBalance();
        to->printBalance();
    } else {
        printf("Failure: Transfer from user %d to user %d %d\n", currentUserID, toWhom, inputAmount);
        users[currentUserID]->printBalance();
        to->printBalance();
    }
}

int main() {
    char job;
    do {
        cout << "Job?" << endl;
        cin >> job;
        if (job == 'N') {
            createUser();
        } else if (job == 'D') {
            deposit();
        } else if (job == 'W') {
            withDraw();
        } else if (job == 'T') {
            transfer();
        }
    } while (job != 'Q');
    return 0;
}
