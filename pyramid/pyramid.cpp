#include <cassert>
#include <stdexcept>

// TODO: Define class Pyramid
class Pyramid {
    public:
      Pyramid(float l, float w, float h) {
        this->Width(w);
        this->Length(l);
        this->Height(h);
    }
      // accessors
      float Length();
      float Width();
      float Height();
      // mutators
      void Length(float l);
      void Width(float w);
      void Height(float h);
    
      float Volume();
      bool isValidInput(float i);
    
    private:
      float length;
      float width;
      float height;
};

// public class members
float Pyramid::Volume() {
    return (this->width * this->length * this->height) / 3;
}

// constructor

// accessor
float Pyramid::Length() { return this->length; };
float Pyramid::Width() { return this->width; } ;
float Pyramid::Height() { return this->height; };

bool Pyramid::isValidInput(float i) {
    if (i < 0) return false;
    else return true;
}

// mutators
void Pyramid::Length(float l) {
   if (!isValidInput(l)) throw "Not valid";
   else {
       this->length = l;
   }
};
void Pyramid::Width(float w) {
   if (!isValidInput(w)) throw "Not valid";
   else {
       this->width = w;
   }
};
void Pyramid::Height(float h) {
   if (!Pyramid::isValidInput(h)) throw "Not valid";
   else {
       this->height = h;
   }
};

// public Volume() function

// Test
int main() {
  Pyramid pyramid(4, 5, 6);
  assert(pyramid.Length() == 4);
  assert(pyramid.Width() == 5);
  assert(pyramid.Height() == 6);
  assert(pyramid.Volume() == 40);

  bool caught{false};
  try {
    Pyramid invalid(-1, 2, 3);
  } catch (...) {
    caught = true;
  }
  assert(caught);
}
