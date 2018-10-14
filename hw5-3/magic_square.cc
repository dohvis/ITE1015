#include <iostream>
#include <cstdlib>

using namespace std;

void fillMagicSquare(int **arr, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            arr[i][j] = 0;
        }

    }


    for (int i = 1, y = 0, x = n / 2; i <= n * n; ++i, --y, ++x) {
        if (y < 0 && x >= n) {
            y += 2;
            x -= 1;
        }


        y = (y + n) % n, x = x % n;

        if (arr[y][x]) {
            y += 2;
            x -= 1;
        }

        arr[y][x] = i;
    }
}


void printMagicSquare(int **arr, int n) {

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << arr[i][j] << ' ';
        }
        cout << endl;
    }
}
