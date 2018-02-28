#include<string>
using std::string;
#include<vector>
using std::vector;
#include <iostream>
using std::cout; using std::endl;
#include "lab07_functions.h"

int main(){

    matrix m = { {1,1,1}, {2,2,2}, {3,3,3} };
    matrix m1 = { {0,0,0}, {1,2,3} };

    matrix m2 ={ {1,1}, {1,1} };
    //cout << same_size(m1,m2);
    string s = matrix_to_str(m,2);
    //cout << s << endl;
    //cout << s.size() << endl;
    scalar_multiply(m);

    return 0;
}
