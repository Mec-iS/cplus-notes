#include <iostream>
using namespace std;

void copy_chars(char* from, char* to, int count) {
  if (from == nullptr || to == nullptr) {
    return;
  }

  while (count > 0) {
    *to++ = *from++;
    count--;
  }
}

int main()
{
  char string[] { "abcdefgk"};
  char buffer[10];

  int c = 8;

  copy_chars(string, buffer, c);

  cout << buffer << endl;
  return 0;
}
