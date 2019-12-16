/* Create a class LineSegment.
Declare an attribute length in class LineSegment.
Define pi (3.14159) with a macro.
Create a class Circle, composed of a LineSegment that represent's the circle's radius. Use this radius to calculate the area of the circle (area of a circle = \pi r^2πr 
2
 ).
Verify the behavior of Circle in main(). */
#include <math.h>
#include <iostream>
#include <assert.h>
using std::pow;

class LineSegment {
    public:
        float length;
        LineSegment(float l): length(l) {}
};

class Circle {
    private:
        LineSegment radius;
    public:
        Circle(LineSegment r): radius(r) {}
        float Area() {
            return pow(this->radius.length, 2.0) * M_PI;
        }
};

int main() {
    LineSegment radius(3.0);
    Circle circle(radius);
    assert(int(circle.Area()) == 28.0);
}