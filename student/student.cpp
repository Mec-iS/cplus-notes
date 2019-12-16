#include <cassert>
#include <stdexcept>
#include <string>
using std::string;

// TODO: Define "Student" class
class Student {
 public:
  Student(string n, int g, float gpa) {
      if (
        !((g >=0 && g <= 12) &&
          (gpa >= 0.0 && gpa <= 4.0))
      ) throw "Invalid value";
      else {
          this->Name(n);
          this->Grade(g);
          this->Gpa(gpa);
      }
  }
  // accessors
  string Name() { return this->name; };
  int Grade() { return this->grade; };
  float Gpa() { return this->gpa; }; 
  // mutators
  void Name(string n) {
    this->name = n;
  };
  void Grade(int g) {
    this->grade = g;
  };
  void Gpa(float g) {
    this->gpa = g;
  };

 private:
  string name;
  int grade;
  float gpa;
};

// TODO: Test
int main() {
    bool fault = false;
    
    try {
        auto stud1 = Student("student one", 5, 3.4);
    } catch (...) {
        fault = true;
    };
    assert(!fault);
    
    try {
        auto stud2 = Student("should fail", -1, 3.4);
        fault = true;
    } catch (...) {
        fault = false;
    };
    assert(!fault);
    
}
