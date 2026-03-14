#include <iostream>
#include <string>
using namespace std;

int main() {
  // Flush after every std::cout / std:cerr
  cout << unitbuf;
  cerr << unitbuf;

  // TODO: Uncomment the code below to pass the first stage
  cout << "$ ";
  string text;
  getline(cin , text);
  cout << text << ": command not found";

}
