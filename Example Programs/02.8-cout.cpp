#include<iostream>
using std::cout; using std::endl; using std::boolalpha;
using std::left; using std::right; using std::fixed;
using std::scientific;

#include<iomanip>
using std::setw; using std::setprecision; using std::setfill;

/* wfp, updated 1/14/15
basic cout stuff
*/

int main(){
  double pi=3.1415926535897932;
  bool bool_true = true;

  // float formating
  cout << scientific;
  cout << "Scientific notation:"<<pi<<endl;
  cout << fixed;
  cout << "Fixed notation:"<<pi<<endl;
  cout << setprecision(3);
  cout << "Fixed notation, 3 decimal points:"<<pi<<endl;

  // widths, justification
  // right sets state, setw must be done for each field!!!
  cout << right << setw(10) << "hi mom" << setw(10) << "bye"<<endl;
  cout << setfill('*');
  cout << right << setw(10) << "hi mom" << left<< setw(10) << "bye"<<endl;

  //boolalpha
  cout << "No bool alpha (default):"<<bool_true <<endl;
  cout << boolalpha;
  cout << "bool alpha set:"<<bool_true <<endl;
}
