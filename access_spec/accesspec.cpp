// This example demonstrates the privacy levels
// between parent and child classes
#include <iostream>
#include <string>
using std::string;

class Vehicle {
public:
    explicit Vehicle(int w, string c): wheels(w), color(c) {};

    void Print() const
    {
        std::cout << "This " << this->color << " vehicle has "
          << this->wheels << " wheels!\n";
    };
private:
    int wheels;
    string color;

};

class Car : public Vehicle {
public:
    using Vehicle::Vehicle;
    bool sunroof = false;
};

class Bicycle : protected Vehicle {
public:
    using Vehicle::Vehicle;
    bool kickstand = true;
};

class Scooter : private Vehicle {
public:
    using Vehicle::Vehicle;
    bool electric = false;
};

int main()
{
    Car car(4, "blue");
    car.Print();

    Bicycle bicycle(2, "gray");

    //bicycle.Print();
    std::cout << "Bicycle is 'protected', cannot print";


    Scooter scooter(2, "red");
    //scooter.Print();
    std::cout << scooter.wheels;
};
