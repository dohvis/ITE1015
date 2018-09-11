#include<stdio.h>

int main()
{
    double arr[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
    double *parr = &arr[0];
    for(int i=0;i<5;i++) {
        *parr *= 2;
        printf("%f\n", *parr); 
        parr = parr + 1;
    }
    return 0;
}
