#include<iostream>
using std::cout; using std::endl; using std::boolalpha; using std::fixed;
#include<iomanip>
using std::setprecision;
/*
wfp, 7/15/13
wfp, updated 1/14/15
initializer vs assign, auto converts basic types
*/

int main () {
  // 4 different initializers. Part of the declaration! Type on left.
    short my_short;
    long my_long = 23;
    bool my_bool(1);   // c++11
    double my_double = {3.1415926535897932}; // c++11
    
    //cout << boolalpha;        // set out stream state, print bools as strings
    cout << fixed << setprecision(6);
    cout << "Bool:"<<my_bool<<", Int:"<<my_long<<",int:"<<my_short
	 <<", Double:"<<my_double<<endl;

    cout << "my_short:"<<my_short<<endl;
    my_short = -1;
    cout << "my_short:"<<my_short<<endl;
    my_bool = 117;   // assignment, not init. Note no type info on left.
    // auto convert to 1 (true) for anything except 0 (false)
    cout << "my_bool:"<<my_bool<<endl;  
    
    my_long = my_double;  // assignment, auto truncation of the fraction part
    cout << "my_long from my_double:"<<my_long<<endl;
     
    my_double = my_long;  // assignment, automatic addition of frac part;
    cout << "my_double from my_long:"<<my_double<<endl;  
}
