#include <iostream>

int main()
{
    int id = 0; // Define an integer variable

    // capture by reference (immutable)
    auto f0 = [&id]() { std::cout << "a) ID in Lambda = " << id << std::endl; };

    // capture by value (mutable)
    // value can mutate, but only inside the scope
    // (does not effect original value)
    // Copyng into closure's scope
    auto f1 = [id]() mutable {
        id = id + 1;
        std::cout << "b) ID in Lambda = " << id << std::endl; };
    f1(); // call the closure and execute the code witin the Lambda
    std::cout << "c) ID in Main = " << id << std::endl;

    f0();

    // capture by reference (mutable)
    auto f2 = [&id]() mutable { std::cout << "d) ID in Lambda = " << ++id << std::endl; };
    f2();
    std::cout << "e) ID in Main = " << id << std::endl;

    // pass parameter
    auto f3 = [](const int id) { std::cout << "f) ID in Lambda = " << id << std::endl; };
    f3(++id);

    // observe the effect of capturing by reference at an earlier point in time


    return 0;
}
