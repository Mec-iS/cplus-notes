
/*
1. The unique pointer `std::unique_ptr` is a smart pointer which exclusively
  owns a dynamically allocated resource on the heap. There must not be a second
  unique pointer to the same resource.

2. The shared pointer `std::shared_ptr` points to a heap resource but does not
  explicitly own it. There may even be several shared pointers to the same
  resource, each of which will increase an internal reference count. As soon
  as this count reaches zero, the resource will automatically be deallocated.

3. The weak pointer `std::weak_ptr` behaves similar to the shared pointer but
  does not increase the reference counter.
*/

#include <memory>

void RawPointer()
{
    int *raw = new int; // create a raw pointer on the heap
    *raw = 1; // assign a value
    delete raw; // delete the resource again
}

void UniquePointer()
{
    std::unique_ptr<int> unique(new int); // create a unique pointer on the stack
    *unique = 2; // assign a value
    // delete is not neccessary
}

// because the smart pointer is declared on the stack, its destructor is
// invoked when the smart pointer goes out of scope, even if an exception is thrown.
