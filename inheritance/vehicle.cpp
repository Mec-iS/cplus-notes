#include <iostream>
#include <string>
using std::string;

class Vehicle {
public:
    explicit Vehicle(int w, string c, string m) : wheels(w), color(c), manufacturer(m) {};
    int wheels;
    string color;
    string manufacturer;
    
    void Print() const
    {
        std::cout << "This " << this->color << " vehicle has " << this->wheels << " wheels!\n";
        std::cout << "It was made by " << this->manufacturer << std::endl;
    }
};

class Car : public Vehicle {
public:
    using Vehicle::Vehicle;
    bool sunroof = false;
};

class Bicycle : public Vehicle {
public:
    using Vehicle::Vehicle;
    bool kickstand = true;
};

class Motorbike: public Vehicle {
    public:
      using Vehicle::Vehicle;
};

int main() 
{
    Car car(4, "Blue", "Tesla");
    car.sunroof = true;
    car.Print();
    if(car.sunroof)
        std::cout << "it has a sunroof!\n";
    
    Motorbike b(2, "White", "Yamaha");
    b.Print();
};
