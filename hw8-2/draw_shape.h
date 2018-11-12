class Shape {
public:
    Shape();

    Shape(/* 필요한 인수 */);

    double GetArea();

    int GetPerimeter();

    void Draw(int canvas_width, int canvas_height) {};
protected:
    // 모든 도형에 공통적인 속성 정의
};

class Rect : Shape {

};

class Square : Shape {

};

class Diamond : Shape {

};
