#include<iostream>
using std::cout; using std::endl;
#include<string>
using std::string;

#include "17.5-clock.h"


int main(){
    Clock my_clk;                
    Clock a_clk(2,2,"AM");
    Clock some_clk(a_clk);                  // direct call to copy

    cout << "OP<< TEST: " << some_clk << endl;       // op<<
    my_clk = a_clk = some_clk;              // op= chained
    cout << "CHAINED ASSIGN TEST: "<< my_clk << endl; // << op
    my_clk = a_clk + a_clk;                 // op+ followed by op=
    cout << "ADD TEST: "<< my_clk << endl;    // op<<
    my_clk = a_clk + 1;                     // implicit conversion, op+, op=
    cout << "Add INT TEST: "<< my_clk << endl;// op<<
    my_clk = 1 + a_clk;                     // implicit conversion, op+, op=
                                            // won't compile as a method!
    cout << "COMMUTE TEST: "<< my_clk << endl;// op<<
}
