#include <iostream>
#define SIZE 5

using namespace std;

struct person {
    char name[10];
    int age;
};


int main()
{
    struct person Person; 
    cin >> Person.name;
    cin >> Person.age;
    cout <<"name: " << Person.name << endl << "age: " << Person.age << endl;
    return 0;
}
