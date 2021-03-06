#include<string>
using std::string;
#include<utility>
using std::pair;
#include<iostream>
using std::ostream;
#include<fstream>
using std::ifstream;
#include <sstream>
using std::istringstream;
using std::copy;

#include "lab11_arrays.h"

bool is_even(long l){
	return l%2;
}

void print_array(long ary[], size_t sz, ostream& out){
	std::ostringstream oss;
	for(int i = 0; i<sz; i++){
		oss << ary[i] << ", ";
	}
	string s = oss.str();
    s = s.substr(0,s.size()-2); //remove trailing comma
    out << s;
}

size_t fill_from_file(long* (& ary), string f_name){

	string count_temp;
	size_t count = 0;
	long l_count = 0;
	string value;
	string line;
    std::ifstream inFile(f_name);
	

	//error handling for no file found
    if(!inFile){
        throw std::runtime_error("invalid argument");
    }

	while(getline(inFile,line)){
        std::istringstream iss (line);
		iss >> count_temp;
		l_count = stol(count_temp);
		ary = new long[l_count]; //initialize array

		//populate arry based on first num
		for(int i = 0; i < l_count; i++){
			iss >> value;
			ary[i] = stol(value);
		}
	}
	count = l_count;
	return count;
}

size_t concatenate(long* (& ary1), size_t sz1, long ary2[], size_t sz2){
	long temp_ary[sz1];
	copy(ary1, ary1+sz1, temp_ary); //copy ar1 to temp
	delete []ary1;
	ary1 = new long[sz1+sz2];
	copy(temp_ary, temp_ary+sz1, ary1);
	copy(ary2, ary2+sz2, ary1+sz1);
	return sz1+sz2;
}

pair<long*, size_t> copy_evens(long ary[], size_t sz){
	long* test;
	return std::make_pair(test,sz);
}