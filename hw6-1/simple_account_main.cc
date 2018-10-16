#include <iostream>

#include "simple_account.h"

using namespace std;

int main() {
    char job;
    int userCnt = 0, currentUserID = 0;
    int inputAmount = 0;
    User *users[10]; //배열 선언

    do {
        cout << "Job?" << endl;
        cin >> job;
        if (job == 'N') {
            if (userCnt > 9) {
                printf("Can't create user\n");
                printf("Max user count: 10, current user count: %d \n", userCnt);
                continue;
            }
            User *newUser = new User(userCnt);
            users[userCnt] = newUser;
            userCnt += 1;
            printf("Account for user %d registered\n", newUser->id);
            printf("Balance of user %d: %d\n", newUser->id, newUser->balance);
        } else if (job == 'D') {
            cin >> currentUserID >> inputAmount;
            if(currentUserID >= userCnt) {
                printf("Account does not exist\n");
                continue;
            }
            bool isSuccess = users[currentUserID]->deposit(inputAmount);
            if (isSuccess) {
                printf("Success: Deposit to user %d: %d\n", currentUserID, inputAmount);
                printf("Balance of user %d: %d\n", currentUserID, users[currentUserID]->balance);
            } else {
                printf("Failure: Deposit from user %d: %d\n", currentUserID, inputAmount);
                printf("Balance of user %d: %d\n", currentUserID, users[currentUserID]->balance);
            }
        } else if (job == 'W') {
            cin >> currentUserID >> inputAmount;
            if(currentUserID >= userCnt) {
                printf("Account does not exist\n");
                continue;
            }
            bool isSuccess = users[currentUserID]->withDraw(inputAmount);
            if (isSuccess) {
                printf("Success: Withdraw to user %d: %d\n", currentUserID, inputAmount);
                printf("Balance of user %d: %d\n", currentUserID, users[currentUserID]->balance);
            } else {
                printf("Failure: Withdraw from user %d: %d\n", currentUserID, inputAmount);
                printf("Balance of user %d: %d\n", currentUserID, users[currentUserID]->balance);
            }
        } else if (job == 'T') {
            int toWhom;
            cin >> currentUserID >> toWhom >> inputAmount;
            if(currentUserID >= userCnt or toWhom >= userCnt) {
                printf("Account does not exist\n");
                continue;
            }
            User *to = users[toWhom];
            bool isSuccess = users[currentUserID]->transfer(to, inputAmount);
            if (isSuccess) {
                printf("Success: Transfer from user %d to user %d %d\n", currentUserID, toWhom, inputAmount);
                printf("Balance of user %d: %d\n", currentUserID, users[currentUserID]->balance);
                printf("Balance of user %d: %d\n", toWhom, to->balance);
            } else {
                printf("Failure: Transfer from user %d to user %d %d\n", currentUserID, toWhom, inputAmount);
                printf("Balance of user %d: %d\n", currentUserID, users[currentUserID]->balance);
                printf("Balance of user %d: %d\n", toWhom, to->balance);
            }
        }

    } while (job != 'Q');
    return 0;
}
