#include <iostream>
#include <cstdlib>

using namespace std;

void swap(int &a, int &b) {
    int tmp;
    tmp = b;
    b = a;
    a = tmp;
}

void bubbleSort(int *array, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (array[j] > array[j + 1]) {
                swap(array[j], array[j + 1]);
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    int *array = (int *) malloc(sizeof(int *) * n);
    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }
    bubbleSort(array, n);
    for (int i = 0; i < n; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
    free(array);
    return 0;
}
