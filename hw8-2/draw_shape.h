class Shape {
public:
    Shape();
//    Shape(int x, int y, char brush) {};

    virtual double GetArea() {
        return 0.0;
    };

    virtual int GetPerimeter() = 0;

    virtual void Draw(int canvas_width, int canvas_height) {};

protected:
    char brush;
    int x, y;
    // 모든 도형에 공통적인 속성 정의
};

class Rect : public Shape {
public:
    Rect() {};

    Rect(int x, int y, char brush, int width, int height);

    double GetArea();

    int GetPerimeter();

    void Draw(int canvas_width, int canvas_height);

private:
    int width, height;
};

class Square : public Shape {
public:
    Square() {};

    Square(int x, int y, char brush, int width, int height);

    double GetArea();

    int GetPerimeter();

    void Draw(int canvas_width, int canvas_height);

private:
    int width, height;
};

class Diamond : public Shape {
public:
    Diamond() {};

    Diamond(int x, int y, int distance, char brush);

    double GetArea();

    int GetPerimeter();

    void Draw(int canvas_width, int canvas_height);

private:
    int distance;
};
