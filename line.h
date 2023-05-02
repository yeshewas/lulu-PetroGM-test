#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cmath>

using namespace std;
class Line {
public:
    Point p1, p2;

    Line(double x1, double y1, double x2, double y2) : p1(x1, y1), p2(x2, y2) {}

    void Draw() const {
        cout << "line from (" << p1.x << ", " << p1.y << ") to (" << p2.x << ", " << p2.y << ")" << endl;
    }

    bool Intersect(const Point& other) const {
        return other.Intersect(*this);
    }

    bool Intersect(const Line& other) const {
        double x1 = p1.x, y1 = p1.y, x2 = p2.x, y2 = p2.y;
        double x3 = other.p1.x, y3 = other.p1.y, x4 = other.p2.x, y4 = other.p2.y;

        double den = (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4);
        if (den == 0) return false;

        double t = ((x1 - x3) * (y3 - y4) - (y1 - y3) * (x3 - x4)) / den;
        double u = -((x1 - x2) * (y1 - y3) - (y1 - y2) * (x1 - x3)) / den;

        if (t >= 0 && t <= 1 && u >= 0 && u <= 1) {
            double x = x1 + t * (x2 - x1);
            double y = y1 + t * (y2 - y1);
            cout << "The line and the line have intersection at (" << x << ", " << y << ")" << endl;
            return true;
        }

