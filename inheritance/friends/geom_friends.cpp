#include <assert.h>

class Square {
    private:
        float side;
        friend class Rectangle;
    public:
        Square(float s): side(s) {}
};

class Rectangle {
    private:
        float width;
        float height;
    public:
        Rectangle(Square sq): width(sq.side), height(sq.side) {}  // this friend class can access Square private
        float Area() {
            return width * height;
        }
};


int main()
{
    Square square(4);
    Rectangle rectangle(square);
    assert(rectangle.Area() == 16); 
}