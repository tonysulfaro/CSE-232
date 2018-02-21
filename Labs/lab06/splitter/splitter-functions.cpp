#include<vector>
#include<string>
#include<iostream>
#include "splitter-functions.h"
using std::vector; using std::ostream;
using std::string; using std::endl; using std::cout;


vector<string> split (const string &s, char separator){
    vector<string> result;
    string temp;

    for(auto ch: s){
        if(ch != separator){
            temp += ch;
        }
        else{
            result.push_back(temp);
            temp = "";
        }
    }

    return result;
}

void print_vector (ostream &out, const vector<string> &v){
    for (auto str: v){
        cout << "test" << endl;
        cout << str << endl;
    }
}
