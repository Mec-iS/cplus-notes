/**
Pointers of pointers for a list of Pointers
*/

#include <iostream>
using namespace std;

int main()
{
    // list of pointers to static strings.
    // ab is an array of pointers to const char.
    // initialised to 26 elements but only 6 assigned, others are initialised to nullptr
    const char* ab[26]
    {
        "alpha",
        "bravo",
        "charlie",
        "delta",
        "echo",
        "foxtrot"
    };

    for (const char **p = ab; *p != nullptr; ++p)
    {
        cout << *p << " ";
    }
    cout << endl;

    return 0;
}
