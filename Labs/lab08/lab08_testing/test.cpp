#include<vector>
using std::vector;
#include<string>
using std::string; using std::to_string;
#include<map>
using std::map;
#include<utility>
using std::pair;
#include <iostream>
using std::cout; using std::endl;

int main(){

    pair<long, vector<long>> test = {120, {1,2,3,4,4}};

    for(auto element: test.second){
        cout << element << endl;
    }

    return 0;
}
