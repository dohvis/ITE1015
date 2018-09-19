#include <iostream>
#define SIZE 5

using namespace std;

typedef struct {
    char name[7];
    int score;
} Person;

void printScoreStars(Person *persons, int len) {
    int starCnt = 0;
    for(int i=0;i<len;i++) {
        starCnt = persons[i].score / 5;
        printf("%s ", persons[i].name);
        for(int j=0;j<starCnt;j++) {
            printf("*");
        }
        printf("\n");
    }
}

int main()
{
    Person people[3];
    
    int sum = 0;
    for(int i=0; i<3; i++) {
        cin >> people[i].name;    
        cin >> people[i].score;
    }
     
    printScoreStars(people, 3);
    return 0;
}
