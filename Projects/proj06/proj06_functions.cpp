#include<string>
using std::string;
#include<vector>
using std::vector; using std::to_string;

#include<iostream>
using std::cout; using std::endl;

//convert vector contents to comma delimited string
string vec_2_str(const vector<long>& v){

    string s;

    for(auto element: v){
        s += to_string(element);
        s += ",";
    }
    //truncate string if it has "," at the end
    s = s.substr(0, s.size()-1);

    return s;
}

vector<long> gen_nstep_vector (long limit, long nstep){

    vector<long> generated = {1,1};
    int i = 0;
    long next_element = 0;

    while(next_element <= limit){
        next_element = generated[i]+generated[i+1];
        if(next_element <= limit){
            generated.push_back(next_element);
        }
        i++;
    }
    return generated;
}

string num_to_nstep_coding(long num, long nstep){

    return "string";
}

long nstep_coding_to_num(const string& coding, const vector<long>& nstep_sequence){

    return 100;
}
