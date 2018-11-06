class Number {
protected:
    int _num;
public:
    void setNumber(int num) {
        _num = num;
    }

    int getNumber() {
        return _num;
    }
};

class Square : public Number {
public:
    int getSquare(); // setNumber()로 지정된 숫자의 제곱을 리턴하도록 소스 파일에 구현
};

class Cube : public Square {
public:
    int getCube(); // setNumber()로 지정된 숫자의 세제곱을 리턴하도록 소스 파일에 구현
};
