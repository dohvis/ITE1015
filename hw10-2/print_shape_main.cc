#include <iostream>
#include <vector>

#include "print_shape.h"

/*
 * 사용자부터 ‘c’를 입력받으면 이후에 입력되는 하나의 실수는 Circle 객체의 radius이며,
 * ‘r’을 입력받으면 이후에 입력되는 두 실수는 Rectangle 객체의 width와 height를 의미한다. ‘0’이 입력되면 입력이 끝났음을 의미한다.
 * 사용자로부터 정해지지 않은 개수의 Circle과 Rectangle들의 정보를 임의의 순서로 받아,
 * j이에 맞게 생성되는 Circle혹은 Rectangle 객체를 std::vector<Shape*> 타입의 벡터 shapes에 저장한다.
사용자가 ‘0’을 입력하여 입력이 종료되면, 지금까지 생성된 Circle혹은 Rectangle객체들의 종류와 면적과 둘레를 각 객체의 getTypeString(), getArea(), getPerimeter() 함수를 호출하여 아래와 같이 순서대로 출력한다.

 */

using namespace std;

int main() {
    char mode;
    vector<Shape *> shapes;
    do {
        cin >> mode;
        if (mode == 'c') {
            double radius;
            cin >> radius;
            Circle *c = new Circle(radius);
            shapes.emplace_back(c);
        } else if (mode == 'r') {
            double width, height;
            cin >> width >> height;
            Rectangle *r = new Rectangle(width, height);
            shapes.emplace_back(r);
        }
    } while (mode != '0');
    for (auto &shape : shapes) {
        cout << shape->getTypeString() << ", ";
        cout << shape->getArea() << ", ";
        cout << shape->getPerimeter() << ", ";
        cout << endl;
        delete shape;
    }
    return 0;
}
