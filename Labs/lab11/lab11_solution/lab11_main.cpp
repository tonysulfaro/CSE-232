#include<iostream>
using std::cout; using std::endl; using std::cin;
#include<fstream>
using std::ifstream;
#include<string>
using std::string;

#include "lab11_arrays.h"

int main(){
    long *ary;
    long ary2[] ={10,11,12,13,14};
    size_t ary2_sz = 5;

    print_array(ary2, ary2_sz, cout);
    cout << endl;
    
    size_t sz_file = fill_from_file(ary, "tables.txt");
    print_array(ary, sz_file, cout);
    cout << endl;
    
    size_t sz_concat = concatenate(ary, sz_file, ary2, ary2_sz);
    print_array(ary, sz_concat, cout);
    cout << endl;
    
    pair<long*, size_t> p = copy_evens(ary, sz_concat);
    print_array(p.first, p.second, cout);
    cout << endl;
    // add code to delete dynamic memory after this
    delete [] ary;
    delete [] p.first;
}
