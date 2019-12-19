#include <iostream>

class MyInt
{
    int *_p; // pointer to heap data
public:
    MyInt(int *p = NULL): _p(p) {}
    ~MyInt()
    {
        std::cout << "resource " << *_p << " deallocated" << std::endl;
        delete _p;
    }
    int &operator*() { return *_p; } // // overload dereferencing operator
};


int main()
{
  MyInt integer = MyInt(new int(15)); // new returns an address

  double den[] = {1.0, 2.0, 3.0, 4.0, 5.0};
  for (size_t i = 0; i < 5; ++i)
  {
      // allocate MyInt on the stack, it encapsulates the pointer to a value
      // on the heap
      MyInt en(new int(i));

      // use the resource
      std::cout << *en << "/" << den[i] << " = " << *en / den[i] << std::endl;
  }  // deallocation happens here <<<<<<<<<<<<<<<<<
}

//
// WRONG <<<<<<<<<<<<<<<<<<<<
//
// int main()
// {
//     double den[] = {1.0, 2.0, 3.0, 4.0, 5.0};
//     for (size_t i = 0; i < 5; ++i)
//     {
//         MyInt *en = new MyInt(new int(i)); <------ new is called explicitly on the object
//
//         // use the resource
//         std::cout << **en << "/" << den[i] << " = " << **en / den[i] << std::endl;
//
//     } <------- deallocation does not happen as it should be explicitly called
//     return 0;
// }
