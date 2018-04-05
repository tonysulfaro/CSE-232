
#include <iostream>
using std::cout;
using std::endl;
using std::ostream;
#include <sstream>
using std::ostringstream;
#include "lab12_vector.h"
using student::vector;

template<typename T>
void print_vector(vector<T>& v, ostream& out){
    ostringstream oss;
    for(auto i = 0u; i < v.size(); i++) {
        oss << v[i] << ", ";
    }
    out << oss.str().substr(0, oss.str().length() - 2) << endl;
}

int main ()
{
    vector<long> v;
    cout << "Size     : " << v.size() << endl;
    cout << "Capacity : " << v.capacity() << endl;

    for(auto i = 0u; i < 12; i++) {
        v.push_back(i);
    }
    cout << "Size     : " << v.size() << endl;
    cout << "Capacity : " << v.capacity() << endl;
    cout << "v        : ";
    print_vector(v, cout);
    cout << "v.front(): " << v.front() << endl;
    cout << "v.back() : " << v.back() << endl;
    cout << endl;

    try {
        cout << v[100] << endl;
    }
    catch (const std::range_error& e) {
        cout << "An exception was caught, with message '" 
             << e.what() << "'" << endl;
    }

    try {
        vector<long> v;
        cout << v.front() << endl;
    }
    catch (const std::range_error& e) {
        cout << "An exception was caught, with message '" 
             << e.what() << "'" << endl;
    }

    try {
        vector<long> v;
        cout << v.back() << endl;
    }
    catch (const std::range_error& e) {
        cout << "An exception was caught, with message '" 
             << e.what() << "'" << endl;
    }
    cout << endl;

    vector<char> v1={'a','b','c','d'};
    vector<char> v_copy(v1);
    cout << "copy size:"<<v_copy.size()<<", copy cap:"<<v_copy.capacity() << endl;
    v_copy.push_back('y');
    v_copy.push_back('z');    
    print_vector(v_copy, cout);
    cout << "copy size:"<<v_copy.size()<<", copy cap:"<<v_copy.capacity() << endl;
    print_vector(v1, cout);    
    cout << "orig size:"<<v1.size()<<", orig cap:"<<v1.capacity() << endl;


    
    vector<long> v2(v);
    v2.push_back(100);
    v2[4] = 444;
    cout << "v  : ";
    print_vector(v, cout);
    cout << "v2 : ";
    print_vector(v2, cout);
    cout << endl;

    vector<long> v3;
    v3 = v2;
    v3.push_back(200);
    cout << "v2 : ";
    print_vector(v2, cout);
    cout << "v3 : ";
    print_vector(v3, cout);
    cout << endl;
}

