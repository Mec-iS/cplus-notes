/**
Virtual methods is how C++ declares abstract classes.
**/

#include <assert.h>
#include <math.h>
using std::pow;

class Shape {
public:
  virtual float Area() const = 0;  // initialised to 0, derived classes must override
  virtual float Perimeter() const = 0;
};


class Rectangle: public Shape {
public:
  Rectangle(float w, float h): width(w), height(h) {};
  float Area() const {
    return this->width * this->height;
  };
  float Perimeter() const {
    return (this->width + this->height) * 2; 
  };

private:
  float width;
  float height;
};


class Circle: public Shape {
public:
  Circle(float r): radius(r) {};
  float Area() const {
    return M_PI * pow(this->radius, 2.0);
  };
  float Perimeter() const {
    return 2 * M_PI * this->radius; 
  };

private:
  float radius;
};

// Test in main()
int main() {
  double epsilon = 0.1; // useful for floating point equality

  // Test circle
  Circle circle(12.31);
  assert(abs(circle.Perimeter() - 77.35) < epsilon);
  assert(abs(circle.Area() - 476.06) < epsilon);

  // Test rectangle
  Rectangle rectangle(10, 6);
  assert(rectangle.Perimeter() == 32);
  assert(rectangle.Area() == 60);
}