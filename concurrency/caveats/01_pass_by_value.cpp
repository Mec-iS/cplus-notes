/*

Passing by value to a thread
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

it undergoes some important caveats:
Classes from the standard template library usually implement a deep copy behavior.
 The only safe way to tell whether a data structure can be safely passed is by
 looking at its implementation: Does it contain only atomic data types or are
 there pointers somewhere? If this is the case, does the data structure implement
 the copy constructor (and the assignment operator) correctly? Also, if the data
 structure under scrutiny contains sub-objects, their respective implementation
 has to be analyzed as well to ensure that deep copies are made everywhere.
*/
#include <iostream>
#include <thread>
#include <future>

class Vehicle
{
public:
    //default constructor
    Vehicle() : _id(0), _name(new std::string("Default Name"))
    {
        std::cout << "Vehicle #" << _id << " Default constructor called" << std::endl;
    }

    //initializing constructor
    Vehicle(int id, std::string name) : _id(id), _name(new std::string(name))
    {
        std::cout << "Vehicle #" << _id << " Initializing constructor called" << std::endl;
    }

    // setter and getter
    void setID(int id) { _id = id; }
    int getID() { return _id; }
    void setName(std::string name) { *_name = name; }
    std::string getName() { return *_name; }

private:
    int _id;
    std::string *_name;
};

int main()
{
    // create instances of class Vehicle
    Vehicle v0;    // default constructor
    Vehicle v1(1, "Vehicle 1"); // initializing constructor

    // launch a thread that modifies the Vehicle name
    std::future<void> ftr = std::async([](Vehicle v) {
        std::this_thread::sleep_for(std::chrono::milliseconds(500)); // simulate work
        v.setName("Vehicle 2");
    },v0);  // <<<<<<<<<<<<<<<<< pass by value, shallow copy <<<<<<<<<<<<<<<<<<<

    v0.setName("Vehicle 3");

    ftr.wait();
    std::cout << v0.getName() << std::endl;

    return 0;
}
