#include <iostream>
#include "world_clock.h"

using namespace std;

int main() {
    string mode;
    WorldClock wc = WorldClock();
    do {
        cin >> mode;
        if (mode == "set") {
            cin >> wc;
        } else if (mode == "tick") {
            int seconds;
            cin >> seconds;
            wc.Tick(seconds);
            cout << wc;
        }
    } while (mode != "quit");

    return 0;
}