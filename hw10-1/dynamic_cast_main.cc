/*
 * 사용자로부터 정해지지 않은 개수의 “B”, “C”, “D” 문자열을 임의의 순서로 받아, 각각의 문자열에 해당하는 B, C, D 클래스의 객체를 하나씩 생성해서
 * std::vector<B*> 타입의 벡터 objects에 저장한다.
사용자가 “0”을 입력하여 입력이 종료되면, for문에서 objects의 각 요소를 순회하며
 objects의 각 요소가 C타입 객체인 경우에는 C::test_C()를, D타입 객체인 경우에는 D::test_D()를 호출하도록 한다 (dynamic_cast를 이용).
 B타입 객체인 경우에는 아무 것도 출력하지 않는다.
단, 이 문제는 dynamic_cast의 사용 방법을 연습하기 위한 것으로, 실제로 이러한 용도로 dynamic_cast를 사용하는 코드는 바람직하지 않게 설계된 코드라는 것을 기억하기 바람.
사용이 끝난 objects의 각 요소는 할당받은 메모리를 해제해야 한다
 */

#include <iostream>
#include <vector>
#include "dynamic_cast.h"

using namespace std;

int main() {
    string input;
    vector<B *> objects;
    do {
        std::cin >> input;
        if (input == "B") {
            B *b = new B();
            objects.emplace_back(b);
        } else if (input == "C") {
            C *c = new C();
            objects.emplace_back(c);
        } else if (input == "D") {
            D *d = new D();
            objects.emplace_back(d);
        }
    } while (input != "0");
    for (auto &obj : objects) {
        C *isC = dynamic_cast<C *>(obj);
        D *isD = dynamic_cast<D *>(obj);
        if (isC) {
            isC->test_C();
        } else if (isD) {
            isD->test_D();
        } else {

        }
        delete obj;
    }
}