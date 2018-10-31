#include <string>
#include <iostream>

#include "message_book.h"

using namespace std;

int main() {
    string cmd, args;
    MessageBook *mb = new MessageBook();

    do {
        cin >> cmd;
        if (cmd == "add") {
            int number;
            cin >> number;
            cin.ignore();
            getline(cin, args);
            mb->AddMessage(number, args);
        } else if (cmd == "print") {
            cin >> args;
            cout << mb->GetMessage(stoi(args)) << endl;
        } else if (cmd == "delete") {
            cin >> args;
            mb->DeleteMessage(stoi(args));
        } else if (cmd == "list") {
            for (const int &number: mb->GetNumbers()) {
                cout << number << ": " << mb->GetMessage(number) << endl;
            }
        }
    } while (cmd != "quit");
    return 0;
}