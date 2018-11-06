#include "number.h"

int Square::getSquare() {
    int num = this->getNumber();
    return num * num;
}

int Cube::getCube() {
    int num = this->getNumber();
    return num * num * num;
}