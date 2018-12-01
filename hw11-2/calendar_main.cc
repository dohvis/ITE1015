#include <iostream>
#include "calendar.h"

using namespace std;

int main() {
    string mode;
    Date date = Date();
    do {
        cin >> mode;
        if (mode == "set") {
            cin >> date;
        } else if (mode == "next_day") {
            date.NextDay();
            cout << date;
        } else if (mode == "next") {
            string line;
            int n;
            getline(cin, line);
            if (line != "") {
                line = line.substr(1);
                n = stoi(line);
            }
            date.NextDay(n);
            cout << date;
        } else {

        }

    } while (mode != "quit");

    return 0;
}
