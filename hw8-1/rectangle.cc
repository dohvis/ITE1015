#include <stdio.h>
#include "rectangle.h"

Rectangle::Rectangle(int width, int height) {
    this->width = width;
    this->height = height;
}    // 필요한 데이터를 멤버변수로 저장하도록 소스 파일에 구현
int Rectangle::getArea() {
    return this->width * this->height;
}    // 사각형의 넓이를 구하도록 소스 파일에 구현
int Rectangle::getPerimeter() {
    return this->width * 2 + this->height * 2;
}    // 사각형의 둘레를 구하도록 소스 파일에 구현

Square::Square(int width) {
    this
}    // 부모 클래스의 생성자를 적절히 호출하도록 소스 파일에 구현
void Square::print() {
    printf("%dx%d square\n", this->width, this->height);
    printf("Area: %d\n", this->getArea());
    printf("Perimeter: %d\n", this->getPerimeter());
}    // Square객체의 정보를 출력 (아래 실행 예 참조)

NonSquare::Square(int width, int height) {

}    // 부모 클래스의 생성자를 적절히 호출하도록 소스 파일에 구현
void NonSquare::print() {
    printf("%dx%d Nonsquare\n", this->width, this->height);
    printf("Area: %d\n", this->getArea());
    printf("Perimeter: %d\n", this->getPerimeter());
}    // NonSquare 객체의 정보를 출력 (아래 실행 예 참조)

