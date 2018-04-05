
#include <iostream>
using std::cout;
using std::endl;
#include "lab12_vector.h"
using student::vector;
#include<stdexcept>

int main ()
{
    vector<long> v;
    cout << "Size     : " << v.size() << endl;
    cout << "Capacity : " << v.capacity() << endl;
    
    for(auto i = 0l; i < 12; i++) {
        v.push_back(i);
    }
    cout << "Size     : " << v.size() << endl;
    cout << "Capacity : " << v.capacity() << endl;
    
    for(auto i = 0u; i < v.size(); i++) {
        cout << v[i] << ", ";
    }
    cout << endl;

    try {
        cout << v[100] << endl;
    }
    catch (const std::range_error& e) {
        cout << "A standard exception was caught, with message '" 
             << e.what() << "'" << endl;
    }
}
