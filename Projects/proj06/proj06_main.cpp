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
    vector<long> v = gen_nstep_vector(976,6);

    //num_to_nstep_coding
    string result = num_to_nstep_coding(976,6);
    cout << result << endl;

    //nstep_coding_to_num
    long result_num = nstep_coding_to_num(result, v);
    cout << result_num << endl;

}
