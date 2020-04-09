#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    // pointer to constant char
    char const* cp = "arbitrary null terminated text string";
    // pointer to allocated buffer of same length in the heap
    char* buffer = new char[ strlen(cp)+1 ];

    strcpy(buffer, cp);

    cout << "buffer = " << buffer << endl;
    delete[] buffer;

    return 0;
}
