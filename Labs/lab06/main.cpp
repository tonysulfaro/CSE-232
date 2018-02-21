/* 
 * File:   main.cpp
 * Author: bill
 *
 * Created on October 10, 2013, 2:13 PM
 */

#include <iostream>
#include<string>
#include<vector>

using std::cout;using std::endl;using std::cin;
using std::vector;
using std::string;

#include"extra.h"

/*
 * 
 */
int main() {
    string result;
    vector<string> v{"this", "is", "a", "test"};
    result = my_fun(v);
    cout << "Result:"<<result<<endl;
    
    
}
