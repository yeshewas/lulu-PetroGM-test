#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cmath>

class Rectangle {
public:
    Point p1, p2;

    Rectangle(double x1, double y1, double x2, double y2) : p1(x1, y1), p2(x2, y2) {}

    void Draw() const {
        cout << "rectangle at (" << p1.x << ", " << p1.y << "), (" << p2.x << ", " << p2.y << ")" << endl;
    }

    bool Intersect(const Point& other) const {
        return other.x >= p1.x && other.x <= p2.x && other.y >= p1.y && other.y <= p2.y;
    }

    bool Intersect(const Line& other) const;
    bool Intersect(const Rectangle& other) const;
    bool Intersect(const Circle& other) const;
};
