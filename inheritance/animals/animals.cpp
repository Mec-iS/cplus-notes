/*
https://www.learncpp.com/cpp-tutorial/114-constructors-and-initialization-of-derived-classes/
*/
#include <iostream>
#include <string>
using std::string;
// Define base class Animal
class Animal {
    public:
      string color;
      string name;
      int age;
      Animal(string c, string n, int a): color(c), name(n), age(a) {};
      friend std::ostream& operator<<(std::ostream &strm, const Animal &a) {
        // override << for stream to have a to_string method
        return strm << "Animal " << a.name << " is " << a.color << ": age " << a.age << "; ";
      }
      void makeSound();
};

class Snake: public Animal {
    private:
      int length;
    public:
      Snake(string c, string n, int a, int l):
        Animal(c, n, a), length(l) {}
      friend std::ostream& operator<<(std::ostream &strm, const Snake &s) {
        // override << for stream to have a to_string method
        return strm << "Snake " << s.name << " is " << s.color << ": age, length "
               << s.age << ", " << s.length << "; ";
      }
      void makeSound() {
        std::cout << "Fsshhhhh" << std::endl;
      }

};

class Cat: public Animal {
    private:
      int height;
    public:
      Cat(string c, string n, int a, int h):
        Animal(c, n, a), height(h) {}
      friend std::ostream& operator<<(std::ostream &strm, const Cat &c) {
        // override << for stream to have a to_string method
        return strm << "Cat " << c.name << " is " << c.color << ": age, height "
               << c.age << ", " << c.height << "; ";
      }
      void makeSound() {
        std::cout << "Meooow" << std::endl;
      }

};

int main() {
    Animal animal("Brown", "Fo", 3);
    std::cout << animal << std::endl;

    Snake s("Green", "Wil", 8, 85);
    std::cout << s << std::endl;

    Cat c("White", "Gee", 4, 13);
    std::cout << c << std::endl;

    s.makeSound();
    c.makeSound();
}