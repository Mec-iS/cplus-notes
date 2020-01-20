/*
Ways of passing an instantiated object to a thread
*/
#include <iostream>
#include <thread>

class Vehicle
{
public:
    void operator()()
    {
        std::cout << "Vehicle object has been created \n" << std::endl;
    }
};


int main()
{
    // create thread

    // ERROR: this is ambiguous to the compiler
    //std::thread t0(Vehicle()); // C++'s most vexing parse

    // SOLUTION: the function object is copied into internal storage accessible
    //          to the new thread, and the new thread invokes the operator ()
    std::thread t1( (Vehicle()) ); // Add an extra pair of parantheses

    std::thread t2 = std::thread( Vehicle() ); // Use copy initialization

    std::thread t3{ Vehicle() };// Use uniform initialization with braces

    // do something in main()
    std::cout << "Finished work in main \n";

    // wait for thread to finish
    t1.join();
    t2.join();
    t3.join();

    return 0;
}


/*
EXAMPLE WITH PASSING DATA in the instances

#include <iostream>
#include <thread>

class Vehicle
{
public:
    Vehicle(int id) : _id(id) {}
    void operator()()
    {
        std::cout << "Vehicle #" << _id << " has been created" << std::endl;
    }

private:
    int _id;
};

int main()
{
    // create thread
    std::thread t = std::thread(Vehicle(1)); // Use copy initialization

    // do something in main()
    std::cout << "Finished work in main \n";

    // wait for thread to finish
    t.join();

    return 0;
}

*/
