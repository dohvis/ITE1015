#include <iostream>
using namespace std;
typedef struct
{
    int xpos;
    int ypos;
} Point;

void scale2x(Point* pp)
{
    pp->xpos *= 2;
    pp->ypos *= 2;
}

int main() {
    Point sPoint[3];
    for(int i=0;i<3;i++) {
        cin >> sPoint[i].xpos;
        cin >> sPoint[i].ypos;
        scale2x(&sPoint[i]);
    }

    for(int i=0;i<3;i++) {
        printf("[%d] %d %d\n", i, sPoint[i].xpos, sPoint[i].ypos);
    }

    return 0;
}
