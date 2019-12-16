#include <string>
#include <cstring>
#include <iostream>

using std::string;

class Car {
    // TODO: Declare private attributes
    private:
      int horsepower;
      int weight;
      char* brand;
    // TODO: Declare getter and setter for brand
    public:
      string GetBrand();
      void SetBrand(string brand);
        
};

// Define setters
void Car::SetBrand(string brand) {
    this->brand = new char[brand.length() + 1];
    strcpy(this->brand, brand.c_str());
}

// Define getters
string Car::GetBrand() {
    int size = sizeof(this->brand) / sizeof(char); 
    string s = ""; 
    for (int i = 0; i < size; i++) { 
        s += this->brand[i]; 
    } 
    return s; 
}

// Test in main()
int main() 
{
    Car car;
    car.SetBrand("Tesla");
    std::cout << car.GetBrand() << "\n";   
}
