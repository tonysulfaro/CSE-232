
#include <iostream>
using std::cout;
using std::endl;
#include "lab12_vector.h"
using student::vector;

int main ()
{
    vector<long> v;
    cout << "Size     : " << v.size() << endl;
    cout << "Capacity : " << v.capacity() << endl;
}

