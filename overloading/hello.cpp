/*
Create a function hello() that outputs, "Hello, World!"
Create a class Human.
Overload hello() by creating a function hello(Human human). This function should output, "Hello, Human!"
Create 2 more classes and use those classes to further overload the hello() function.
*/
#include <string>
#include <iostream>

class Human {};
class Airplane {};
class Boat {};

std::string hello() {
    std::cout << "Hello, World!" << std::endl;
}

std::string hello(Human human) {
    std::cout << "Hello, Human" << std::endl;
}

std::string hello(Airplane airplane) {
    std::cout << "Hello, Airplane" << std::endl;
}

std::string hello(Boat boat) {
    std::cout << "Hello, Boat" << std::endl;
}

int main() {
    hello();
    hello(Human());
    hello(Airplane());
    hello(Boat());
}