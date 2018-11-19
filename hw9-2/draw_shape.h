#include <string>
#include <vector>

using namespace std;

class Canvas {
public:
    Canvas(int row, int col);

    void Resize(int w, int h);

    bool DrawPixel(int y, int x, char brush);

    std::string Print() const;

    void Clear();

private:
    int row;
    int col;

    vector<char> block;
    vector<char *> pixels;
};

class Shape {
public:
    Shape(int x, int y, char brush);

    virtual ~Shape() = default;

    virtual std::string ShapeInfo() const = 0;

    virtual void Draw(Canvas &canvas) const = 0;

    int x, y;
    char brush;
private:

};

class Rectangle : public Shape {
public:
    Rectangle(int x, int y, int width, int height, char brush);

    std::string ShapeInfo() const;

    void Draw(Canvas &canvas) const;

private:
    int width, height;
};

class UpTriangle : public Shape {
public:
    UpTriangle(int x, int y, int height, char brush);

    std::string ShapeInfo() const;

    void Draw(Canvas &canvas) const;

private:
    int height;
};

class DownTriangle : public Shape {
public:
    DownTriangle(int x, int y, int height, char brush);

    std::string ShapeInfo() const;

    void Draw(Canvas &canvas) const;

private:
    int height;
};

class Diamond : public Shape {
public:
    Diamond(int x, int y, int distance, char brush);

    std::string ShapeInfo() const;

    void Draw(Canvas &canvas) const;

private:
    int distance;
};

