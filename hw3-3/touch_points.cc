#include <iostream>
#include <stdio.h>

using namespace std;

typedef struct
{
	double x;
	double y;
} Point;

typedef struct
{
    char name[7];
    Point points[3];
} Person;

int getDistance(Point point) {
    return point.x * point.x + point.y * point.y;
}

void calcFarthestPoint(Person person, Point* farthestPoint) {
    int farthestPointIndex= -1;
    int farthestDistance=0;
    int distance;
    for(int i=0;i<3;i++) {
        distance = getDistance(person.points[i]);
        if(farthestDistance < distance) {
            farthestDistance = distance;
            farthestPointIndex = i;
        }
    }
    *farthestPoint = person.points[farthestPointIndex];
}


int main(void){
    Person persons[3];
    int buf[6];
    int cnt = 0;
    for(int i=0;i<3;i++) {
        scanf("%7s %lf %lf %lf %lf %lf %lf", persons[i].name, 
            &persons[i].points[0].x, &persons[i].points[0].y,
            &persons[i].points[1].x, &persons[i].points[1].y,
            &persons[i].points[2].x, &persons[i].points[2].y);
    }
    for(int i=0;i<3;i++) {
        Point farthestPoint;
        calcFarthestPoint(persons[i], &farthestPoint);
        printf("%s (%0.lf, %0.lf)\n", persons[i].name, farthestPoint.x, farthestPoint.y);
    }
    return 0;
}


