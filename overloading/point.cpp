#include <assert.h>

// TODO: Define Point class
  // TODO: Define public constructor
  // TODO: Define + operator overload
  // TODO: Declare attributes x and y

class Point {
public:
    Point(int x, int y): x(x), y(y) {};

    Point operator+(Point p) {
        return Point(this->x + p.x, this->y + p.y);
    }

    int x;
    int y;
};

// Test in main()
int main() {
  Point p1(10, 5), p2(2, 4);
  Point p3 = p1 + p2; // An example call to "operator +";
  assert(p3.x == p1.x + p2.x);
  assert(p3.y == p1.y + p2.y);
}