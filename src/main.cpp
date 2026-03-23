#include <iostream>
#include <string>
#include <filesystem>
#include <cstdlib>
#include <sstream>
using namespace std;
namespace fs = std::filesystem ;

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
   else if (text == "type echo" || text =="type exit"|| text =="type type"){
    cout <<text.substr(5) << " is a shell builtin" << endl;
   }
   
   else if(text.find("type ")==0){
     const char* inv = getenv("PATH");
     string pathstr(inv);
     stringstream ss(inv);
     string dir;
     bool found = false;
     while (getline(ss, dir, ':') ){
      fs::path fullPath = fs:: path (dir) / text.substr(5);
      if ( fs::exists(fullPath))
      {
      }
      if ((fs::status(fullPath).permissions() & fs::perms::owner_exec) != fs::perms::none){
         found = true;
          cout << text.substr(5) << " is " << fullPath.string() <<endl;
          break;
      }
      
     }
     if(!found){
      cout << text.substr(5) <<": not found" << endl;
     }
   }
   else{
    cout << text << ": command not found" << endl;
   }
   
  }
}