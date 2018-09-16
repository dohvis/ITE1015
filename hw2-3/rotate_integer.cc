#include <iostream>

using namespace std;

void swap(int *a, int *b) {
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

void rotateLeft(int* pa, int* pb, int* pc){
    swap(pa, pb);
    cout << pa << pb << pc << endl;
    swap(pb, pc);
}

void rotateRight(int* pa, int* pb, int* pc){
    swap(pa, pb);
    swap(pa, pc);
}

int main(void){
    int a=10, b=20, c=30;
    int mode;
    while (1) {
        cout << a << ":" << b << ":"  << c << endl;
        cin >> mode;
        if(mode == 1) {
            rotateLeft(&a, &b, &c);
        } else if (mode == 2) {
            rotateRight(&a, &b, &c);
        } else {
            return 0;
        }
    }
}

