#include <iostream>

using namespace std;

typedef struct _ComplexNumber {
    double r;
    double i;
} ComplexNum;


void printComplex(ComplexNum c) {
    printf("%lf + %lfi\n", c.r, c.i);
}

void printAddComp(ComplexNum a, ComplexNum b) {
    ComplexNum cn = {};
    cn.r = a.r + b.r;
    cn.i = a.i + b.i;
    printComplex(cn);
}

void printMulComp(ComplexNum a, ComplexNum b) {
    ComplexNum cn;
    cn.r = a.r * b.r - a.i * b.i;
    cn.i = a.r * b.i + a.i * b.r;
    printComplex(cn);
}

int main() {
    ComplexNum cn1;
    ComplexNum cn2;
    cin >> cn1.r >> cn1.i >> cn2.r >> cn2.i;
    cout << "복소수1:" << endl;
    printComplex(cn1);
    cout << "복소수2:" << endl;
    printComplex(cn2);

    cout << "두 복소수의 합:" << endl;
    printAddComp(cn1, cn2);

    cout << "두 복소수의 곱:" << endl;
    printMulComp(cn1, cn2);
    return 0;
}


