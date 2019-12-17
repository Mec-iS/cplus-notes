#include <iostream>

void myFunction(int &&val) // <- ownership pass to this scope
{
    std::cout << "val = " << val << std::endl;
}

int main()
{
    myFunction(42);

    // equivalent to:
    int i = 42;
    myFunction(std::move(i)); // <- ownership is passed to the callee

    // i does not exist anymore in the caller scope

    return 0;
}
