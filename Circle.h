#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cmath>
class Circle {
public:
    Circle(double x, double y, double r) : x(x), y(y), r(r) {}

    void Draw() const {
        cout << "circle at (" << x << ", " << y << "), radius = " << r << endl;
    }

    bool Intersect(const Point& other) const {
        return (other.x - x) * (other.x - x) + (other.y - y) * (other.y - y) <= r * r;
    }

    bool Intersect(const Circle& other) const {
        return (other.x - x) * (other.x - x) + (other.y - y) * (other.y - y) <= (r + other.r) * (r + other.r);
    }
t
    bool Intersect(const Line& other) const {
    // calculate the distance between the center of the circle and the line
    double distance = abs((other.y2 - other.y1) * x - (other.x2 - other.x1) * y + other.x2 * other.y1 - other.y2 * other.x1) / sqrt(pow(other.y2 - other.y1, 2) + pow(other.x2 - other.x1, 2));
    return distance <= r;
}
}
