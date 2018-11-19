#include "draw_shape.h"
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int row, col;
    cin >> row >> col;

    Canvas canvas(row, col);
    cout << canvas.Print();
    vector<Shape *> shapes;
    string mode;
    string args;
    int x, y;
    char brush;
    int width, height;

    do {
        cin >> mode;
        if (mode == "add") {
            cin >> args;
            if (args == "rect") {
                cin >> x >> y >> width >> height >> brush;
                auto *r = new Rectangle(x, y, width, height, brush);
                shapes.emplace_back(r);
            } else if (args == "tri_up") {
                cin >> x >> y >> height >> brush;
                auto *ut = new UpTriangle(x, y, height, brush);
                shapes.emplace_back(ut);
            } else if (args == "tri_down") {
                cin >> x >> y >> height >> brush;
                auto *dt = new DownTriangle(x, y, height, brush);
                shapes.emplace_back(dt);
            } else if (args == "diamond") {
                int dist;
                cin >> x >> y >> dist >> brush;
                auto *d = new Diamond(x, y, dist, brush);
                shapes.emplace_back(d);
            }
        } else if (mode == "delete") {
            int idx;
            cin >> idx;
            int cnt = 0;
            for (vector<Shape *>::const_iterator it = shapes.begin(); it != shapes.end(); it++) {
                if (cnt == idx) {
                    shapes.erase(it);
                    break;
                }
                cnt += 1;
            }
        } else if (mode == "draw") {
            canvas.Clear();
            for (vector<Shape *>::const_iterator it = shapes.begin(); it != shapes.end(); it++) {
                (*it)->Draw(canvas);
            }
            cout << canvas.Print();
        } else if (mode == "dump") {
            for (int i = 0; i < shapes.size(); i++) {
                cout << i << ' ' << shapes[i]->ShapeInfo() << endl;
            }
        } else if (mode == "resize") {
            cin >> width >> height;
            canvas.Resize(width, height);
        }
    } while (mode != "quit");


    for (auto *shape : shapes) {
        delete shape;
    }
    return 0;
}
