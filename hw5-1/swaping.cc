#include <iostream>

using namespace std;

void swapInt(int& n1, int& n2) {
    int tmp;
    tmp = n1;
    n1 = n2;
    n2 = tmp;
}

void swapString(std::string& s1, std::string& s2) {
    string tmp;
    tmp = s1;
    s1 = s2;
    s2 = tmp;
}

int main() {
    int n1, n2;
    string s1, s2;
    cin >> n1 >> n2 >> s1 >> s2;
    printf("n1: %d, n2: %d, s1: %s, s2: %s\n", n1, n2, s1.c_str(), s2.c_str());
    swapInt(n1, n2);
    swapString(s1, s2);
    printf("n1: %d, n2: %d, s1: %s, s2: %s\n", n1, n2, s1.c_str(), s2.c_str());
    return 0;
}
