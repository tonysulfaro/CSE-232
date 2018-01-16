#include<iostream>
#include<string>

/* wfp, 7/8/13
Hello world with name prompt and using decls
*/

// using declarations
using std::cin;   // console input stream
using std::cout;  // console output stream
using std::endl;  // end of line marker
using std::string; // STL string package

// The below is a using directive and brings in everything
// don't use it 
// using namespace std;

int main () {
  string name;
  cout << "What's your name:";
  cin >> name;
  cout << "Hello " << name << '!' << endl;
  // return 0; // optional
}
    
