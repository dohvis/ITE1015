#include <iostream>
#include "magic_square.h"

using namespace std;

int main() {
    int n;
    cin >> n;

    if (n % 2 == 0 || n < 0)
        return 0;

    int **arr;

    arr = (int **) malloc(sizeof(int *) * n);
    for (int i = 0; i < n; ++i) {
        arr[i] = (int *) malloc(sizeof(int) * n);
    }


    fillMagicSquare(arr, n);
    printMagicSquare(arr, n);

    for (int i = 0; i < n; ++i) {
        free(arr[i]);
    }
    free(arr);
    return 0;
}
