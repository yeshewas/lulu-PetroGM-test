#include <iostream>
#include <fstream>
#include <vector>
#include "Point.h"
#include "Line.h"
#include "Circle.h"
#include "Rectangle.h"

using namespace std;

int main() {
    ifstream inputFile("input.txt");
    if (!inputFile.is_open()) {
        cerr << "Failed to open input file." << endl;
        return 1;
    }

    vector<Shape*> shapes;
    string shapeType;
    while (inputFile >> shapeType) {
        if (shapeType == "point") {
            double x, y;
            inputFile >> x >> y;
            Point* point = new Point(x, y);
            shapes.push_back(point);
        }
        else if (shapeType == "line") {
            double x1, y1, x2, y2;
            inputFile >> x1 >> y1 >> x2 >> y2;
            Line* line = new Line(x1, y1, x2, y2);
            shapes.push_back(line);
        }
        else if (shapeType == "circle") {
            double x, y, r;
            inputFile >> x >> y >> r;
            Circle* circle = new Circle(x, y, r);
            shapes.push_back(circle);
        }
        else if (shapeType == "rect") {
            double x1, y1, x2, y2;
            inputFile >> x1 >> y1 >> x2 >> y2;
            Rectangle* rect = new Rectangle(x1, y1, x2, y2);
            shapes.push_back(rect);
        }
    }

    for (auto shape : shapes) {
        shape->Draw();
    }

    for (size_t i = 0; i < shapes.size(); ++i) {
        for (size_t j = i + 1; j < shapes.size(); ++j) {
            Shape* shape1 = shapes[i];
            Shape* shape2 = shapes[j];
            if (shape1->Intersect(*shape2)) {
                cout << "Intersection between ";
                shape1->PrintType();
                cout << " and ";
                shape2->PrintType();
                cout << " at ";
                shape1->Intersect(*shape2).Print();
                cout << endl;
            }
            else {
                cout << "No intersection between ";
                shape1->PrintType();
                cout << " and ";
                shape2->PrintType();
                cout << endl;
            }
        }
    }

    for (auto shape : shapes) {
        delete shape;
    }

    return 0;
}

