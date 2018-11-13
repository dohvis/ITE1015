
/*
 * global scope에 void printObjectTypeInfo1(A* object), void printObjectTypeInfo2(A& object) 라는 함수들을 각각 선언하고,
 * 두 함수 모두 인자로 전달받은 객체의 getTypeInfo()를 호출하여 얻은 string 객체를 출력하도록 구현한다.
 *
 * std::vector<A*> 타입의 벡터 objects에 A, B, C 클래스의 객체를 각각 1개씩 new로 생성하여 넣고,
 * objects의 각 요소를 인자로 하여 printObjectTypeInfo1()와 printObjectTypeInfo2() 함수를 순서대로 호출한다.
 * 사용이 끝난 objects의 각 요소는 할당 받은 메모리를 해제해야 하며, 프로그램 코드 전체에 걸쳐 type casting 연산자는 사용하면 안 된다.

 */

#include <vector>
#include "print_info.h"

using namespace std;

int main() {
    vector<A *> objects;
    A *a = new A();
    B *b = new B();
    C *c = new C();
    objects.emplace_back(a);
    objects.emplace_back(b);
    objects.emplace_back(c);
    for (vector<A *>::const_iterator it = objects.begin(); it != objects.end(); it++) {
        printObjectTypeInfo1(*it);
        printObjectTypeInfo2(**it);
    }
    delete a;
    delete b;
    delete c;
    return 0;
}