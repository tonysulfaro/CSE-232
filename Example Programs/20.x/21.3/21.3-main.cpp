#include<iostream>
using std::cout; using std::endl; using std::ostream;
#include<string>
using std::string;

#include "21.3-singlelink.h"

int main () {
  SingleLink<string>sl;

  sl.append_back("beds");
  sl.append_front("tables");
  sl.append_back("chairs");
  cout << sl << endl << endl;

  sl.insert_after("stuff", "tables");
  cout << sl << endl;
  SingleLink<string> s2(sl);
  s2.append_back("junk");
  s2.append_front("pools");
  cout << sl << endl << endl;
  cout << s2 << endl << endl;
  sl = s2;
  sl.append_back("something");
  cout << sl << endl << endl;
  cout << s2 << endl << endl;
}
