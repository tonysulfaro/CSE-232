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

//generate vector up to limit based on nstep fibonacci. nstep is how many elements to add to get next value
vector<long> gen_nstep_vector (long limit, long nstep){

    vector<long> generated = {1,1};
    long next_element = 0;

    //generate nstep amount in generated vector
    while(generated.size() < nstep){

        for(int i = 0; i< generated.size(); i++){
            next_element+=generated[i];
        }
        generated.push_back(next_element);
        next_element = 0;
    }

    //generate next of the sequence until it hits the limit
    while(next_element <= limit){
        //have to make this a loop somehow
        for(int n = generated.size()-nstep; n<generated.size(); n++){
            next_element += generated[n];
        } // this is just being a huge pos
        //next_element = generated[i]+generated[i+1];
        if(next_element <= limit){
            generated.push_back(next_element);
            next_element = 0;
        }
        //i++;
    }

    return generated;
}

//returns a binary string which represents num as the nstep sequence
string num_to_nstep_coding(long num, long nstep){

    string result;
    long remain = num;
    vector <long> nth_fibonacci = gen_nstep_vector(num,nstep);

    for(int i = nth_fibonacci.size()-1; i != 0; i--){
        if((remain - nth_fibonacci[i]) >= 0){
            remain -= nth_fibonacci[i];
            result += "1";
        }
        else{
            result += "0";
        }
    }
    reverse(result.begin(), result.end());
    //result += "1";
    return result;
    //return "string";
}

long nstep_coding_to_num(const string& coding, const vector<long>& nstep_sequence){

    long result = 0;

    for(int i = 0; i <= coding.size(); i++){
        (coding[i] == '1') ? (result += nstep_sequence[i+1]) : (result += 0);
        //cout << "coding: " << coding[i] << " num: " << nstep_sequence[i+1] << " result: " << result << endl;

    }

    return result;
}
