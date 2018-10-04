#include <iostream>

using namespace std;

typedef struct person {
    string name;
    int age;
} Person;

int main() {
    int personCnt;
    cin >> personCnt;
    Person *people = new Person[personCnt];
    for(int i=0; i < personCnt; i++) {
        cin >> people[i].name >> people[i].age;
    }
    for(int i=0; i < personCnt; i++) {
        printf("Name:%s, Age:%d\n", people[i].name.c_str(), people[i].age);
    }
    delete []people;
    return 0;
}

