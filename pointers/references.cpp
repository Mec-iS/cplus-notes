/**
References, in contrast to pointers, refers directly to the value; not to
 the address of the values.
*/
#include <iostream>
using namespace std;

int main()
{
    int i = 10;
    int &ref = i;
    i = i + 10;
    ref = ref * 10;
    cout << "i = " << i << endl;

    int* ip = &ref;
    cout << "ip = " << *ip << endl;

    // When the program modifies references or dereferenced pointers,
    // it modifies the pointed-to variable.
    *ip = 33;
    cout << "i = " << i << ", *ip = " << * ip
         << ", ref = " << ref << endl;
    return 0;
}
