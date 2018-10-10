#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
    int i = 1;
    int sum = 0;
    int argv2int;
    string finalStr;
    while (argv[i] != NULL) {
        argv2int = atoi(argv[i]);
        if (argv2int == 0) {
            finalStr += argv[i];
        } else {
            sum += argv2int;
        }
        i += 1;
    }
    cout << finalStr << endl;
    cout << sum << endl;
    return 0;
}
