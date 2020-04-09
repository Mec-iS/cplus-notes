#include <iostream>
using namespace std;

struct noisy
{
    noisy() { cout << "constructing noisy" << endl; }
    ~noisy() { cout << "destroying noisy" << endl; }
    int a;
};

int main()
{
    cout << "getting a noisy array" << endl;
    // allocate array of structs
    noisy* pnoisy = new noisy[3];

    pnoisy[0].a = 5;
    cout << "pnoisy[0] = " << pnoisy[0].a << endl;
    cout << "deleting noisy array" << endl;
    delete[] pnoisy;

    return 0;
}
