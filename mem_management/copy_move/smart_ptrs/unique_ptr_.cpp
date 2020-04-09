#include <iostream>
#include <memory>
#include <cstring>

using namespace std;

struct noisy
{
    noisy() { cout << "default constructing noisy" << endl; }
    noisy(int i) { cout << "constructing noisy: arg " << i << endl; }
    ~noisy() { cout << "destroying noisy" << endl; }
};

int main()
{
    unique_ptr<noisy> u1(new noisy);
    unique_ptr<noisy> u2;
    u2.reset(new noisy(100));
    unique_ptr<noisy[]> u3(new noisy[3]);
    unique_ptr<noisy[]> u4(new noisy[2]{1});
    unique_ptr<noisy> u5;

    cout << "before transfer of ownership u1 = " << u1.get()
         << ", u5 = " << u5.get() << endl;
    u5.reset(u1.release());
    cout << "after transfer of ownership u1 = " << u1.get()
         << ", u5 = " << u5.get() << endl;

    u1 = move(u5);
    cout << "after second transfer u1 = " << u1.get()
         << ", u5 = " << u5.get() << endl;

    unique_ptr<char[]> buf(new char[20]);
    strcpy(buf.get(), "xyzzy");
    cout << "buf = " << buf.get() << endl;
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
