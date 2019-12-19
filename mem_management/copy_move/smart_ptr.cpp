/*
In essence, smart pointers are classes that are wrapped around raw pointers.
 By overloading the -> and * operators, smart pointer objects make sure that
 the memory to which their internal raw pointer refers to is properly deallocated.
 This makes it possible to use smart pointers with the same syntax as raw pointers.
*/
