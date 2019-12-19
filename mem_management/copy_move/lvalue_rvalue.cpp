/*
every expression in C++ has a type and belongs to a "value category".

Two of them are important for common programming practices:
* Lvalues (LVALUE) have an address that can be accessed. They are expressions whose
   evaluation by the compiler determines the identity of objects or functions.

* Prvalues (or RVALUE) do not have an address that is accessible directly. They are
  temporary expressions used to initialize objects or compute the value of the
  operand of an operator.

Usage of operations (`&`, `*`, ..) on the right or left of the assigment can change
 value category. I.E. Using the address operator `&` we can generate an lvalue
 from an rvalue and assign it to another lvalue: `int *j = &i`;

*/
#include <iostream>

void myFunction(int &val)  // <- this is also a LVALUE REFERENCE
{
    std::cout << "val = " << val << std::endl;
}

void myFunctionRight(int &&val)  // <- this is also a RVALUE REFERENCE
{
    std::cout << "val = " << val << std::endl;
}

int main()
{
    // initialize some variables on the stack
    int i, j, *p;

    // correct usage of lvalues and rvalues

    i = 42; // i is an lvalue and 42 is an rvalue

    p = new int;
    *p = i; // the dereferenced pointer is an lvalue
    delete p;

    ((i < 42) ? i : j) = 23; // the conditional operator returns an lvalue (eiter i or j)

    // incorrect usage of lvalues and rvalues
    //42 = i; // error : the left operand must be an lvalue
    //j * 42 = 23; // error : the left operand must be an lvalue

    //
    // LVALUE REFERENCE (the usual reference)
    //
    p = new int;
    auto ref = &p;

    //
    // RVALUE REFERENCES (&&)
    // copy/assign/delete a value to memory in one line
    //

    // Move semantics and rvalue references make it possible to write code that
    // transfers resources such as dynamically allocated memory from one object
    // to another in a very efficient manner and also supports the concept of
    // exclusive ownership,

    int w = 1;
    int y = 2;
    int k = w + y;

    myFunctionRight(w+y); // <- this would be an error without &&value in function

    return 0;
}
