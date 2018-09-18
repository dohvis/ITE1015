#include <iostream>
#define SIZE 5

using namespace std;

struct person {
    char name[10];
    int age;
};

void printStruct(struct person* pPerson) {
    cout <<"name: " << pPerson -> name << endl << "age: " << pPerson -> age << endl;
}

int main()
{
    struct person Person[3]; 
    for(int i=0;i<3;i++) {
        cin >> Person[i].name;
        cin >> Person[i].age;
    }
    for(int i=0; i<3; i++) {
        printStruct(&Person[i]);
    }
    return 0;
}
