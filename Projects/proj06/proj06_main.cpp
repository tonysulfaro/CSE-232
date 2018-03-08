#include<string>
using std::string;
#include<vector>
using std::vector;
#include<iostream>
using std::cout; using std::endl;
#include "proj06_functions.h"

int main(){

    //vec2str testing
    string s = vec_2_str({2,3,4,3,5,6,6,64,2000});
    //cout << s << endl;

    //gen_nstep_vector testing

    vector<long> v = gen_nstep_vector(143,2);
    for(auto element: v){
        cout << element << " " << endl;
    }


    //num_to_nstep_coding
    string result = num_to_nstep_coding(143,2);
    cout << result << endl;

}
