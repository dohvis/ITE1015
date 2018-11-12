#include <iostream>
#include "draw_shape.h"

using namespace std;


Shape::Shape() = default;

Rect::Rect(int x, int y, char brush, int width, int height) {
    this->x = x;
    this->y = y;
    this->brush = brush;
    this->width = width;
    this->height = height;
}


double Rect::GetArea() {
    return (this->width * this->height);
}

int Rect::GetPerimeter() {
    return 2 * (this->width + this->height);
}

void Rect::Draw(int canvas_width, int canvas_height) {
    int i;
    char shape[canvas_width][canvas_height];
    for (i = this->x; i < x + this->width; i++) {
        for (int j = this->y; j < y + this->height; j++) {
            shape[i][j] = this->brush;
        }
    }
    cout << " ";
    for (i = 0; i < canvas_width; i++) {
        cout << i;
    }
    cout << endl;

    for (i = 0; i < canvas_width; i++) {
        cout << i << " ";
        for (int j = 0; j < canvas_height; j++) {
            if (shape[j][i] == this->brush) {
                cout << this->brush;
            } else {
                cout << ".";
            }

        }
        cout << endl;
    }
}

Square::Square(int x, int y, char brush, int width, int height) {
    this->x = x;
    this->y = y;
    this->brush = brush;
    this->width = width;
    this->height = height;
}


double Square::GetArea() {
    return (this->width * this->height);
}

int Square::GetPerimeter() {
    return 2 * (this->width + this->height);
}

void Square::Draw(int canvas_width, int canvas_height) {
    int i;
    char shape[canvas_width][canvas_height];
    for (i = this->x; i < x + this->width; i++) {
        for (int j = this->y; j < y + this->height; j++) {
            shape[i][j] = this->brush;
        }
    }
    cout << " ";
    for (i = 0; i < canvas_width; i++) {
        cout << i;
    }
    cout << endl;

    for (i = 0; i < canvas_width; i++) {
        cout << i << " ";
        for (int j = 0; j < canvas_height; j++) {
            if (shape[j][i] == this->brush) {
                cout << this->brush;
            } else {
                cout << ".";
            }
        }
        cout << endl;
    }
}

Diamond::Diamond(int x, int y, int distance, char brush) {
    this->x = x;
    this->y = y;
    this->brush = brush;
    this->distance = distance;
}

double Diamond::GetArea() {
    return double((this->distance * 2 + 1) * (this->distance * 2 + 1)) / 2;
}

int Diamond::GetPerimeter() {
    return (this->distance + 1) * 2 * 4;
}

void Diamond::Draw(int canvas_width, int canvas_height) {
    int i;
    char shape[canvas_width][canvas_height];
    for (i = this->y; i < y + this->distance + 1; i++) {
        for (int j = this->x; j < x + (i - y) * 2; j++) {
            shape[i][j] = this->brush;
        }
    }

    cout << " ";
    for (i = 0; i < canvas_width; i++) {
        cout << i;
    }
    cout << endl;

    for (i = 0; i < canvas_width; i++) {
        cout << i << " ";
        for (int j = 0; j < canvas_height; j++) {
            if (shape[i][j] == this->brush) {
                cout << this->brush;
            } else {
                cout << ".";
            }
        }
        cout << endl;
    }
}
