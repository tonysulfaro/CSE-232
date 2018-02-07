#include<iostream>
using std::cout; using std::endl;
#include<string>
#include<cmath>
using std::string;

// note you need algorithm and sort
#include<algorithm>
using std::sort;

/*
  sort individual characters of a string
*/
string alphabet = "abcdefghijklmnopqrstuvwxyz";

//convert location arithmetic string to an integer
long loc_to_dec(string loc){

	long counter = 0;
	string s;

	for(auto chr:loc){
		for(int i = 0; i < alphabet.size(); i++){
			if(chr == alphabet[i]){
				counter += pow(2.0,loc.find(chr));
			}
		}
		cout << loc << endl;
		if(loc[i]==loc[i+1]){
			s+= alphabet[alphabet.find(loc[i])];
		}
	}

	//cout << s << endl;
	for(auto chr: s){
		counter += pow(2,loc.find(chr));
	}
	return counter;
}

//take location string and reduce to abbreviated form
//dont convert to int first, have to abbreviate directly
string abbreviate(string loc){

	string s;

	for(auto chr : loc){
		if(s.find(chr)==string::npos){
			s += chr;
		}
	}
	sort(s.begin(), s.end());
	return s;
}

//convert integer to abbreviated location string
string dec_to_loc(long dec){

}

//take two location strings, add them, provide the integer result
long add_loc (string loc1, string loc2){

	long num = 0;

	string s = loc1 + loc2;
	sort(s.begin(), s.end());
	s = abbreviate(s);
	//num = loc_to_dec(num);
}

int main (){

	string location_string;
	long number = 0;

  	//string test = abbreviate("lksdflkddddjsdf");
  	//cout << test << endl;
	long test = loc_to_dec("aaabbbcccdddeeefffggghhh");
	cout << test << endl;

  	//cin >> location_string;
	//cin >> number;

	long to_decimal = loc_to_dec(location_string);
	string abb = abbreviate(location_string);
	string dec_long = dec_to_loc(to_decimal);
	long add_itself = add_loc(location_string,location_string);

	cout<<loc_to_dec(loc) << " " << abbreviate(loc) << " " << dec_to_loc(i) << " "<< add_loc(loc, loc) << endl;

}
