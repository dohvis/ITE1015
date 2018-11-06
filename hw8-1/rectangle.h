class Rectangle {
public:
    Rectangle(int width, int height);    // 필요한 데이터를 멤버변수로 저장하도록 소스 파일에 구현
    int getArea();    // 사각형의 넓이를 구하도록 소스 파일에 구현
    int getPerimeter();    // 사각형의 둘레를 구하도록 소스 파일에 구현
protected:
    int width, height;
};

class Square : public Rectangle {
public:
    Square(int width);    // 부모 클래스의 생성자를 적절히 호출하도록 소스 파일에 구현
    void print();    // Square객체의 정보를 출력 (아래 실행 예 참조)
};

class NonSquare : public Rectangle {
public:
    Square(int width, int height);    // 부모 클래스의 생성자를 적절히 호출하도록 소스 파일에 구현
    void print();    // NonSquare 객체의 정보를 출력 (아래 실행 예 참조)
};
