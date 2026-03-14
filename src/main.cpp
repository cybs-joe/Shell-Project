#include <iostream>
#include <string>
using namespace std;

int main() {
  // Flush after every std::cout / std:cerr
  string text;
  bool status = true;
  cout << unitbuf;
  cerr << unitbuf;

  // TODO: Uncomment the code below to pass the first stage
 
  while (status = true)
  {
  cout << "$ ";
  getline(cin , text);
  cout << text << ": command not found" << endl;

  }
  
}
