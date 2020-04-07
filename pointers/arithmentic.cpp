#include <iostream>
using namespace std;

int main()
{
  int array[5] { 1, 4, 6, 8, -1};
  int* ptr = array;
  int* element = &array[2];

  cout << "ptr = " << ptr << ", ptr+1 = " << ptr+1
         << ", sizeof(int) = " << sizeof(int) << endl;

  cout << "*(ptr+1) = " << *(ptr+1)
        << ", ptr[1] = " << ptr[1] << endl;
  cout << "*(ptr+4) = " << *(ptr+4)
        << ", ptr[4] = " << ptr[4] << endl;

  cout << "element - ptr = " << element - ptr << endl;

  // the iostrema manipulator boolalpha causes expressions of type bool to print as true
  // or false. Otherwise, they are converted to int, and print as 1 or 0.
  cout << "element == ptr = " << boolalpha << (element == ptr) << endl;
  cout << "element > ptr = " << boolalpha << (element > ptr) << endl;


  return 0;
}
