#include<string>
using std::string;
#include<vector>
using std::vector; using std::to_string;
#include<iostream>
using std::cout; using std::endl; //these are just in here for local testing

//convert vector contents to comma delimited string
string vec_2_str(const vector<long>& v){

    string s;

    //iterate over vector and create string
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

        //for only how ever many nstep is
        for(int i = 0; i< generated.size(); i++){
            next_element+=generated[i];
        }
        generated.push_back(next_element);
        next_element = 0;
    }

    //generate next of the sequence until it hits the limit
    while(next_element <= limit){
        //generate the next elements of vector until the limit is hit
        for(int n = generated.size()-nstep; n<generated.size(); n++){
            next_element += generated[n];
        } // this is just being a huge pos
        if(next_element <= limit){
            generated.push_back(next_element);
            next_element = 0;
        }
    }
    return generated;
}

//returns a binary string which represents num as the nstep sequence
string num_to_nstep_coding(long num, long nstep){

    string result;
    long remain = num;
    vector <long> nth_fibonacci = gen_nstep_vector(num,nstep);

    //iterate over the vector backwards
    for(int i = nth_fibonacci.size()-1; i != 0; i--){
        //check if you can subtract the element from the limit (num)
        if((remain - nth_fibonacci[i]) >= 0){
            remain -= nth_fibonacci[i];
            result += "1";
        }
        else{
            result += "0";
        }
    }
    reverse(result.begin(), result.end());
    return result;
}

//takes a binary string and sequence and generates a number from it
long nstep_coding_to_num(const string& coding, const vector<long>& nstep_sequence){

    long result = 0;

    for(int i = 0; i <= coding.size(); i++){
        //if the char in the string is one add the element of the sequence to the result
        (coding[i] == '1') ? (result += nstep_sequence[i+1]) : (result += 0);
    }
    return result;
}
