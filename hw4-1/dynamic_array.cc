#include <iostream>

using namespace std;

int main() {
    int n=0;
    cin >> n;
    int *dArr = new int[n];
    for(int i=0; i < n; i++) {
        dArr[i] = i;
        cout << dArr[i] << " ";
    }
    cout << endl;
    delete []dArr;
    return 0;
}
