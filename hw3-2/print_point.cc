#include <iostream>

using namespace std;

typedef struct
{
	int xpos;
	int ypos;
} Point;

Point getScale2xPoint(const Point *p) {
    Point newP;
    newP.xpos = 2 * p->xpos;
    newP.ypos = 2 * p->ypos;
    return newP;
}

void swap(int *a, int *b) {

    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

void swapPoint(Point *a, Point *b) {
    swap(&a->xpos, &b->xpos);
    swap(&a->ypos, &b->ypos);
}


int main(void){
    Point p1;
    Point p2;
    cin >> p1.xpos;
    cin >> p1.ypos;
    cout << "Calling getScale2xPoint()" << endl;
    p2 = getScale2xPoint(&p1);
    printf("P1: %d %d\n", p1.xpos, p1.ypos);
    printf("P2: %d %d\n", p2.xpos, p2.ypos);
    cout << "Calling swapPoint()" << endl;
    swapPoint(&p1, &p2);
    printf("P1: %d %d\nP2: %d %d\n", p1.xpos, p1.ypos, p2.xpos, p2.ypos);
    return 0;
}


