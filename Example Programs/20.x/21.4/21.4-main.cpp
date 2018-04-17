#include<iostream>
using std::cout; using std::endl; using std::ostream;
#include<string>
using std::string;

#include "21.4-doublelink.h"

int main () {

    DoubleLink<string> sl;
    sl.append_back("beds");
    sl.append_front("tables");
    sl.append_back("chairs");
    cout << sl << endl << endl;
    Node<string> *n = sl.find("tables");
    if (n != nullptr){
      sl.insert_after("rugs", n);
    cout << sl << endl << endl;      
    }
    
    DoubleLink<string> s2(sl);
    s2.append_back("lamps");
    s2.append_front("sofas");
    cout << sl << endl << endl;
    cout << s2 << endl << endl;
    sl = s2;
    sl.append_back("cabinets");
    cout << sl << endl << endl;
    cout << s2 << endl << endl;    
    
}
