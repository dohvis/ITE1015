#include<stdio.h>

void getSumDiff(int a, int b, int* pSum, int* pDiff) {
    *pSum = a + b;
    *pDiff = a - b;
}

int main()
{
    int pSum;
    int pDiff;
    int a,b;
    scanf("%d %d", &a, &b);
    getSumDiff(a, b, &pSum, &pDiff);
    printf("Sum: %d, diff: %d", pSum, pDiff);
    return 0;
}
