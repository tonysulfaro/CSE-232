#include<vector>
using std::vector;
#include<string>
using std::string;
#include<map>
using std::map;
#include<utility>
using std::pair;
#include "lab08_functions.h"
#include<iostream>
using std::cout; using std::endl;

using Collatz = pair<long, vector<long> >;

map<long, vector<long> > m = {};

int main(){

    auto result = collatz_sequence(m,16);

    for(auto element: result){
        cout << element << endl;
    }

    return 0;
}
