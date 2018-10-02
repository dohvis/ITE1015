#include <iostream>

using namespace std;

int main() {
    string str1, str2;
    string concatStr;
    cin >> str1 >> str2;
    concatStr = str1 + str2;
    cout << concatStr << endl;
    cout << concatStr[0] << endl;
    cout << concatStr[concatStr.length()-1] << endl;
    return 0;
}
