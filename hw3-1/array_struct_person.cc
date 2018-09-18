#include <iostream>
#define SIZE 5

using namespace std;

struct person {
    char name[10];
    int age;
};


int main()
{
    struct person Person[3]; 
    for(int i=0;i<3;i++) {
        cin >> Person[i].name;
        cin >> Person[i].age;
    }
    for(int i=0;i<3;i++) {
        cout <<"name: " << Person[i].name << endl << "age: " << Person[i].age << endl;
    }
    return 0;
}
