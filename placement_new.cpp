/*
An alternative to new/delete
*/
#include <stdlib.h>

int main() {
  // object is constructed using an existing memory block
  void *memory = malloc(sizeof(MyClass));
  MyClass *object = new (memory) MyClass;

  // object has to be explicitly decostructed and memory freed
  object->~MyClass();
  free(memory);
}
