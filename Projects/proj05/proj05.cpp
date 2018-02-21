#include<iostream>
using std::cout; using std::cin; using std::endl; using std::boolalpha;
#include<string>
using std::string; using std::to_string; using std::tolower;
#include<cmath>
#include <locale>
using std::tolower;
#include "proj05_functions.h"

//not needed for now, we will see
const string alphabet = "abcdefghijklmnoprstuvwxyz"; //without 'q'

//clean string of all characters
string clean_string(string s){
    string result;


    for(auto ch: s){
        if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')){
            result += tolower(ch);
            cout << ch << endl;
        }
    }
    return result;
}

//create dat encoding to make it mysterious
string create_encoding(string key){
    string keyword;

    keyword += key;

    for(auto ch: alphabet){
        if(keyword.find(ch)==-1){ //if its not in there add it in
            keyword+=ch;
        }
    }
    //add an 'x' if string isnt long enough
    (keyword.size()<25) ? (keyword+="x"):(keyword = keyword);
    //truncate string if greater than 25
    (keyword.size()>25) ? (keyword = keyword.substr(0,25)) : (keyword = keyword);

    return keyword;
}

//generate that board son
//encode_digraph("he", "example", "keyword") returns "fy"
string encode_digraph(string dg, string block1, string block2){
    string fy;

    return fy;
}

//decode it like MD5
string decode_digraph(string dg, string block1, string block2){
    string he;

    return he;
}

//encode it up with basically SHA512
string encode(string msg, string key1, string key2){
    string encoding;

    string encode1 = create_encoding(key1);
    string encode2 = create_encoding(key2);

    return encoding;
}

//decrypt it
string decode(string msg, string key1, string key2){
    string decoding;

    return decoding;
}

int main(){

    string s = "Hello World";
    string clean = clean_string(s);
    cout << clean << endl;
    s = "keyword";
    string result = create_encoding(s);
    s = "someduplicatewords";
    result = create_encoding(s);

    return 0;
}
