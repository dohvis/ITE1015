#include <stdio.h>

void square(double *pVar) {
    *pVar = *pVar * (*pVar);
}
int main() {
    double dvar;
    scanf("%lf", &dvar);
    square(&dvar);
    printf("%f\n", dvar);
    return 0;
}
