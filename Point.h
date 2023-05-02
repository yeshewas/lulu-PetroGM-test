#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cmath>

using namespace std;

class Point {
public:
    double x, y;

    Point(double x, double y) : x(x), y(y) {}

    void Draw() const {
        cout << "point at (" << x << ", " << y << ")" << endl;
    }

    bool Intersect(const Point& other) const {
        return x == other.x && y == other.y;
    }

    bool Intersect(const Line& other) const;
    bool Intersect(const Rectangle& other) const;
    bool Intersect(const Circle& other) const;
};
