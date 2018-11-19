#include "draw_shape.h"
#include <sstream>
#include <vector>


using namespace std;

Canvas::Canvas(int row, int col) : row(row), col(col), block(row * col), pixels(row) {
    for (int i = 0; i < row; i++) {
        this->pixels[i] = &block[i * col];
    }
    this->Clear();
}

void Canvas::Resize(int w, int h) {
    this->row = h;
    this->col = w;

    this->block = vector<char>(row * col);
    this->pixels = vector<char *>(row);

    for (int i = 0; i < row; i++) {
        this->pixels[i] = &block[i * col];
    }
    this->Clear();
}

bool Canvas::DrawPixel(int y, int x, char brush) {
    auto valid = [](int n, int limit) { return n >= 0 && n < limit; };
    if (valid(x, col) && valid(y, row)) {
        char c[y][x];
        c[y][x] = brush;
        this->pixels.emplace_back((char *) c);
        return true;
    }
    return false;
}

string Canvas::Print() const {
    ostringstream oss;
    oss << ' ';
    for (int i = 0; i < col; i++) {
        oss << (i % 10);
    }
    oss << '\n';

    for (int i = 0; i < row; i++) {
        oss << (i % 10);

        for (int j = 0; j < col; j++) {
            char p = this->pixels[i][j] ? this->pixels[i][j] : '.';
            oss << p;
        }
        oss << '\n';
    }
    return oss.str();
}

void Canvas::Clear() {
    for (int i = 0; i < row * col; i++) {
        this->block[i] = 0;
    }
}

Shape::Shape(int x, int y, char brush) : x(x), y(y), brush(brush) {}


Rectangle::Rectangle(int x, int y, int width, int height, char brush) : Shape(x, y, brush), width(width),
                                                                        height(height) {}


string Rectangle::ShapeInfo() const {
    ostringstream oss;
    oss << "rect " << this->x << ' '
        << this->y << ' '
        << width << ' '
        << height << ' '
        << this->brush;
    return oss.str();
}

void Rectangle::Draw(Canvas &canvas) const {
    int x = this->x;
    int y = this->y;
    char brush = this->brush;

    for (int i = y; i < y + height; i++) {
        for (int j = x; j < x + width; j++) {
            canvas.DrawPixel(i, j, brush);
        }
    }
}

UpTriangle::UpTriangle(int x, int y, int height, char brush) : Shape(x, y, brush), height(height) {}

string UpTriangle::ShapeInfo() const {
    ostringstream oss;
    oss << "tri_up " << this->x << ' '
        << this->y << ' '
        << height << ' '
        << this->brush;
    return oss.str();
}

void UpTriangle::Draw(Canvas &canvas) const {
    int x = this->x;
    int y = this->y;
    char brush = this->brush;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j <= i; j++) {
            canvas.DrawPixel(y + i, x - j, brush);
            canvas.DrawPixel(y + i, x + j, brush);
        }
    }
}

DownTriangle::DownTriangle(int x, int y, int height, char brush) : Shape(x, y, brush), height(height) {
}

string DownTriangle::ShapeInfo() const {
    ostringstream oss;
    oss << "tri_down " << this->x << ' '
        << this->y << ' '
        << height << ' '
        << this->brush;
    return oss.str();
}

void DownTriangle::Draw(Canvas &canvas) const {
    int x = this->x;
    int y = this->y;
    char brush = this->brush;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j <= i; j++) {
            canvas.DrawPixel(y - i, x - j, brush);
            canvas.DrawPixel(y - i, x + j, brush);
        }
    }
}

Diamond::Diamond(int x, int y, int distance, char brush) : Shape(x, y, brush), distance(distance) {}

string Diamond::ShapeInfo() const {
    ostringstream oss;
    oss << "diamond " << this->x << ' '
        << this->y << ' '
        << distance << ' '
        << this->brush;
    return oss.str();
}

void Diamond::Draw(Canvas &canvas) const {
    int x = this->x;
    int y = this->y;
    char brush = this->brush;

    for (int i = 0; i < distance; i++) {
        for (int j = 0; j <= i; j++) {
            canvas.DrawPixel(y + i, x - j, brush);
            canvas.DrawPixel(y + i, x + j, brush);
        }
    }

    int base = y + 2 * distance;
    for (int i = 0; i <= distance; i++) {
        for (int j = 0; j <= i; j++) {
            canvas.DrawPixel(base - i, x - j, brush);
            canvas.DrawPixel(base - i, x + j, brush);
        }
    }
}
