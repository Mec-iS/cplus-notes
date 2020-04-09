#include <iostream>
#include <string>
#include <typeinfo>

using namespace std;

template<typename T>

class Position
{
public:
    Position(T x, T y)
    {
        m_x = x;
        m_y = y;
    }
    T const getX() { return m_x; }
    T const getY() { return m_y; }
private:
    T m_x;
    T m_y;
};

int main()
{
    Position<int> intPosition(1, 3);
    Position<float> floatPosition(1.5f, 3.14f);
    Position<long> longPosition(1, 3);
    cout << "type: " << typeid(intPosition.getX()).name() << " X: "
         << intPosition.getX() << " Y: " << intPosition.getY()
         << endl;

    cout << "type: " << typeid(floatPosition.getX()).name() << " X: "
         << floatPosition.getX() << " Y: " << floatPosition.getY()
         << endl;

    cout << "type: " << typeid(longPosition.getX()).name() << " X: "
         << longPosition.getX() << " Y: " << longPosition.getY()
         << endl;

    return 0;
}

/**
MIT License

Copyright (c) 2019 Training By Packt

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/
