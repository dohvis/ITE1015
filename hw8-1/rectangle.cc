#include <stdio.h>
#include "rectangle.h"

Rectangle::Rectangle(int width, int height) {
    this->width = width;
    this->height = height;
}

int Rectangle::getArea() {
    return this->width * this->height;
}

int Rectangle::getPerimeter() {
    return this->width * 2 + this->height * 2;
}

Square::Square(int width) : Rectangle(width, width) {

}    // 부모 클래스의 생성자를 적절히 호출하도록 소스 파일에 구현
void Square::print() {
    printf("%dx%d square\n", this->width, this->height);
    printf("Area: %d\n", this->getArea());
    printf("Perimeter: %d\n", this->getPerimeter());
}    // Square객체의 정보를 출력 (아래 실행 예 참조)

NonSquare::NonSquare(int width, int height) : Rectangle(width, height) {

}

void NonSquare::print() {
    printf("%dx%d Nonsquare\n", this->width, this->height);
    printf("Area: %d\n", this->getArea());
    printf("Perimeter: %d\n", this->getPerimeter());
}    // NonSquare 객체의 정보를 출력 (아래 실행 예 참조)

