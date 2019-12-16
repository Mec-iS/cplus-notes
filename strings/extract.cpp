#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
using std::string;

int main() {
  const std::string path{"file.txt"};
  string line;
  string key;
  string value;
  std::ifstream filestream(path); // file buffer
  if (filestream.is_open()) {
    while (std::getline(filestream, line)) {
      std::istringstream linestream(line);  // string buffer
      while (linestream >> key >> value) {
          std::cout << key << ": " << value << std::endl;
      }
    }
  }
}
