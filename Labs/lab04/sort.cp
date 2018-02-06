#include<iostream>
using std::cout; using std::endl;
#include<string>
using std::string;

// note you need algorithm and sort
#include<algorithm>
using std::sort;

/*
  sort individual characters of a string
*/

//convert location arithmetic string to an integer
long loc_to_dec(string loc){

}

//take location string and reduce to abbreviated form
//dont convert to int first, have to abbreviate directly
string abbreviate(string loc){

}

//convert integer to abbreviated location string
string dec_to_loc(long dec){

}

//take two location strings, add them, provide the integer result
long add_loc (string loc1, string loc2){

}

int main (){
  string my_str = "aebcd";
  cout << "String was:"<<my_str;
  sort(my_str.begin(), my_str.end());
  cout << ", and sorted is:"<< my_str<<endl;
}
