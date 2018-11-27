#include <iostream>
#include "MyVector.h"

using namespace std;

int char2int(char c) {
    return (int) c - '0';
}

int main() {
    string input;
    int number;
    MyVector *mvA = nullptr;
    MyVector *mvB = nullptr;
    do {
        cin >> input;
        if (input == "new") {
            int arraySize;
            cin >> arraySize;
            mvA = new MyVector(arraySize);
            cout << "enter a" << endl;
            for (int i = 0; i < arraySize; i++) {
                cin >> number;
                mvA->append(number);
            }

            mvB = new MyVector(arraySize);
            cout << "enter b" << endl;
            for (int i = 0; i < arraySize; i++) {
                cin >> number;
                mvB->append(number);
            }
        } else if (input == "a") {
            char inputOperator;
            char objectOrNumber;
            cin >> inputOperator;
            cin >> objectOrNumber;
            if (inputOperator == '+') {
                if (objectOrNumber == 'b') {
                    *mvA += *mvB;
                    cout << *mvA;
                } else {
                    int addedValue = char2int(objectOrNumber);
                    *mvA += addedValue;
                    cout << *mvA;
                }
            } else if (inputOperator == '-') {
                if (objectOrNumber == 'b') {
                    *mvA -= *mvB;
                    cout << *mvA;
                } else {
                    int addedValue = char2int(objectOrNumber);
                    *mvA -= addedValue;
                    cout << *mvA;
                }
            }

        } else if (input == "b") {
            char inputOperator;
            char objectOrNumber;
            cin >> inputOperator;
            cin >> objectOrNumber;
            if (inputOperator == '+') {
                if (objectOrNumber == 'a') {
                    *mvB += *mvA;
                    cout << *mvB;
                } else {
                    int addedValue = char2int(objectOrNumber);
                    *mvB += addedValue;
                    cout << *mvB;
                }
            } else if (inputOperator == '-') {
                if (objectOrNumber == 'a') {
                    *mvA -= *mvB;
                    cout << *mvA;
                } else {
                    int addedValue = char2int(objectOrNumber);
                    *mvA -= addedValue;
                    cout << *mvA;
                }
            }

        }
    } while (input != "quit");
    return 0;
}