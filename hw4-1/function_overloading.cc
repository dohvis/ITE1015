#include <iostream>

using namespace std;

int add(int a, int b) {
    return a + b;
} 

string add(string a, string b) {
    return a + '-' + b;
}

int main() {
    int num1, num2, numResult;
    string str1, str2, strResult;
    cin >> num1 >> num2 >> str1 >> str2;
    numResult = add(num1, num2);
    strResult = add(str1, str2);
    cout << numResult << endl;
    cout << strResult << endl;
    return 0;
}
