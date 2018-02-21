#include<vector>
#include<string>
#include<iostream>
using std::vector; using std::ostream; using std::cin;
using std::string; using std::endl; using std::cout;

#include"splitter-functions.h"

int main(){

    string s;

    cout << "Enter a string to be split: ";
    cin >> s;

    vector<string> split_result = split(s);
    print_vector(cout, split_result);
}
