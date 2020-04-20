/**
Like the other containers we will cover, strings have iterators that can be
 utilized to allow traversal through a string in loops.
*/
#include <iostream>
#include <string>

using namespace std;

int main()

{

    string str(" Hello, I' m a string" );
    str.push_back(' !' );
    str.push_back(' !' );
    cout << str << endl;
    str.pop_back();
    cout << str << endl;

    // notice this will keep existing contents and append x for the rest
    str.resize(25, ' x' );

    // reserve space for 50 chars - capacity()
    str.reserve(50);

    // notice that ! is pushed after the last char not the end of allocated space
    str.push_back(' !' );
    cout << str << endl;
    cout << str.capacity() << endl;
    cout << str.size() << endl;
    str.shrink_to_fit();

    // note : shrink_to_fit is not guaranteed to be exactly size()

    // depending on compiler implementation

    cout << str.capacity() << endl;

    return 0;
}
