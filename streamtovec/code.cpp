#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <ctype.h>
using std::cout;
using std::ifstream;
using std::string;
using std::vector;
using std::istringstream;

// TODO: Add the ParseLine function here.
vector<int> ParseLine(string s) {
  istringstream in_stream(s);
  vector<int> v;
  
  // temporary char
  char c;
 
  do {
    in_stream >> c;
    if (isdigit(c)) {
      int n = c - '0';
      v.push_back(n);
    }} while (in_stream);

  return v;
}

void ReadBoardFile(string path) {
  ifstream myfile (path);
  if (myfile) {
    string line;
    while (getline(myfile, line)) {
      cout << line << "\n";
    }
  }
}

void PrintBoard(const vector<vector<int>> board) {
  for (int i = 0; i < board.size(); i++) {
    for (int j = 0; j < board[i].size(); j++) {
      cout << board[i][j];
    }
    cout << "\n";
  }
}

// #include "test.cpp" // For testing.

int main() {
  // ReadBoardFile("1.board");
  // TestParseLine(); // For testing.
  vector<int> v = ParseLine("0,1,0,0,0,0,");
  for (int i : v)
    cout << i << ' ';
  // Leave commented out.
  // PrintBoard(board);
}