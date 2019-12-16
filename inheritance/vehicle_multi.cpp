#include <iostream>
#include <string>
#include <assert.h>
using std::string;

class Vehicle {
    public:
        Vehicle(string c, int w) : wheels(w), color(c) {};
        int wheels;
        string color;
};

class Car : public Vehicle {
    public:
        Car(string c, int w=4): Vehicle(c, w) {};
};

class Sedan: public Car {
    public:
        bool trunk = true;
        int seats = 4;
        Sedan(string c): Car(c) {}
};

int main() 
{
  Sedan sedan("Blue");
  assert(sedan.trunk == true);
  assert(sedan.seats == 4);
  assert(sedan.wheels == 4);
};
