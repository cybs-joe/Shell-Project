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
 
  while (status && text != "Exit" && text != "exit")
  {
    cout << "$ ";
    getline(cin , text);
    if (text.find("echo ")==0){
      cout << text.substr(5) << endl;
    }
   else if (text == "exit" || text =="Exit" || text == "EXIT"){
    break;
   }
   else{
  cout << text << ": command not found" << endl;
  }
}
  
}
