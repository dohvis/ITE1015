/*
 * Shape 클래스는 순수 가상 함수 (pure virtual function)인 double getArea()와 double getPerimeter(), std::string getTypeString()를 가진다.
Shape을 상속 받는 Circle 클래스의 constructor는 double형 radius를 받으며, 원의 면적과 둘레를 계산하도록 getArea()와 getPerimeter()를 구현한다.
 원주율 PI는 3.141592로 #define하여 사용한다.
 getTypeString()은 “Circle”을 리턴한다.


Shape을 상속 받는 Rectangle 클래스의 constructor는 double형 width와 height를 받으며, 사각형의 면적과 둘레를 계산하도록 getArea()와 getPerimeter()를 구현한다. getTypeString()은 “Rectangle”을 리턴한다.
Circle과 Rectangle에 필요한 멤버 변수를 적절히 추가하여 사용할 것.

 */
#include <iostream>

#define PI 3.141592

using namespace std;

class Shape {
public:
    virtual double getArea() = 0;

    virtual double getPerimeter() = 0;

    virtual string getTypeString() = 0;
};

class Circle : public Shape {
public:
    Circle(double radius) {
        this->radius = radius;
    }

    double getArea() {
        return PI * this->radius * this->radius;
    }

    double getPerimeter() {
        return 2 * PI * this->radius;
    }

    string getTypeString() {
        return "Circle";
    }

private:
    double radius;
};

class Rectangle : public Shape {
public:
    Rectangle(double width, double height) {
        this->width = width;
        this->height = height;
    }

    double getArea() {
        return width * height;
    }

    double getPerimeter() {
        return 2 * (width + height);
    }

    string getTypeString() {

        return "Rectangle";
    }

private:
    double width, height;
};