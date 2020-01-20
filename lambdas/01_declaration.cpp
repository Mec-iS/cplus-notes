#include <iostream>
#include <typeinfo>

int main()
{
    // create lambdas
    int id = 0; // Define an integer variable

    //auto f0 = []() { std::cout << "ID = " << id << std::endl; }; // Error: 'id' cannot be accessed

    id++;
    auto f1 = [id]() { std::cout << "ID = " << id << std::endl; }; // OK, 'id' is captured by value

    std::cout << typeid(f1).name() << '\n';  // this print main

    id++;
    auto f2 = [&id]() { std::cout << "ID = " << id << std::endl; }; // OK, 'id' is captured by reference

    //auto f3 = [id]() { std::cout << "ID = " << ++id << std::endl; }; // Error, 'id' may not be modified

    auto f4 = [id]() mutable { std::cout << "ID = " << ++id << std::endl; }; // OK, 'id' may be modified

    // execute lambdas
    f1();
    f2();
    f4();

    return 0;
}

/*
it is important to note that a Lambda does not exist at runtime. The runtime
 effect of a Lambda is the generation of an object, which is known as closure.
 The difference between a Lambda and the corresponding closure is similar to
 the distinction between a class and an instance of the class. A class exists
 only in the source code while the objects created from it exist at runtime.
*/
