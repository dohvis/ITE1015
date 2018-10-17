#include <iostream>
#include <cstring>

#include "reply_admin.h"

using namespace std;

int main() {
    ReplyAdmin *ra = new ReplyAdmin();
    string input, mode, args;
    do {
        getline(cin, input);

        if (input.find("#remove") != string::npos) {
            if (input.find("-") != string::npos) {
                printf("remove chat");
                ra->removeChat(args[8] - 48, args[10] - 48);
            }
            ra->removeChat(args[8] - 48);
        } else {
            ra->addChat(input);
        }
        ra->printChats();
    } while (mode != "#quit");
    return 0;
}