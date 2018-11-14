#include <iostream>

using namespace std;

class Animal {
public:
    Animal(string name, int age) {
        this->name = name;
        this->age = age;
    }

    virtual void printInfo() {
    }

    string name;
    int age;
};

class Zebra : public Animal {
public:
    Zebra(string name, int age, int numStripes) : Animal(name, age) {
        this->numStripes = numStripes;
    }

    virtual void printInfo() {
        // Zebra, Name: Tom, Age: 2, Number of stripes: 21
        cout << "Zebra, Name: " << this->name << ", Age: " << this->age << ", Number of stripes: " << this->numStripes
             << endl;
    }

    int numStripes;
};

class Cat : public Animal {
public:
    Cat(string name, int age, string favoriteToy) : Animal(name, age) {
        this->favoriteToy = favoriteToy;
    }

    virtual void printInfo() {
        cout << "Cat, Name: " << this->name << ", Age: " << this->age << ", Number of stripes: " << this->favoriteToy
             << endl;
    }

    string favoriteToy;
};
