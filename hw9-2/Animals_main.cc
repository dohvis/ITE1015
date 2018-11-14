#include <iostream>
#include <vector>
#include "Animals.h"

using namespace std;

int main() {
    string mode;

    string name;
    int age;
    vector<Animal *> animals;
    do {
        cin >> mode;
        Animal *a;
        if (mode == "c") {
            string favoriteToy;
            cin >> name >> age >> favoriteToy;
            a = new Cat(name, age, favoriteToy);
        } else if (mode == "z") {
            int numStripes;
            cin >> name >> age >> numStripes;
            a = new Zebra(name, age, numStripes);
        } else {
            a = nullptr;
        }

        if (a != nullptr) {
            animals.emplace_back(a);
        }
    } while (mode != "0");
    for (vector<Animal *>::const_iterator it = animals.begin(); it != animals.end(); it++) {
        (*it)->printInfo();
    }
    for(Animal *a: animals) {
        delete a;
    }
    return 0;
}