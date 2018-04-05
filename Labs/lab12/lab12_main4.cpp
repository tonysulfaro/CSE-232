
#include <iostream>
using std::cout;
using std::endl;
using std::ostream;
#include <sstream>
using std::ostringstream;
#include "lab12_vector.h"
using student::vector;


void print_vector(vector<long>& v, ostream& out)
{
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
    catch (const std::exception& e) {
        cout << "A standard exception was caught, with message '" 
            << e.what() << "'" << endl;
    }

    try {
        vector<long> v;
        cout << v.front() << endl;
    }
    catch (const std::exception& e) {
        cout << "A standard exception was caught, with message '" 
            << e.what() << "'" << endl;
    }

    try {
        vector<long> v;
        cout << v.back() << endl;
    }
    catch (const std::exception& e) {
        cout << "A standard exception was caught, with message '" 
            << e.what() << "'" << endl;
    }
    cout << endl;

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

    for (auto i = 0u; i < 10; i++) {
        v.pop_back();
    }
    cout << "v.front()    : " << v.front() << endl;
    cout << "v.back()     : " << v.back() << endl; 
    cout << "v.size()     : " << v.size() << endl;
    cout << "v.capacity() : " << v.capacity() << endl;

    v.clear();
    cout << endl;
    cout << "v.size()     : " << v.size() << endl;
    cout << "v.capacity() : " << v.capacity() << endl;
}

