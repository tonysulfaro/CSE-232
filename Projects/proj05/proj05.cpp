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

    for(auto ch: key){
        if(keyword.find(ch)==-1){
            keyword+= ch;
        }
    }

    for(auto ch: alphabet){
        if(keyword.find(ch)==-1 && key.find(ch) == -1){ //if its not in there add it in
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
    string result;

    char first_letter = dg[0];
    char second_letter = dg[1];

    cout << dg << endl;

    /*  Location information:
        row = index/5 (integer division)
        col = index %5
        index = row * 5 + col */

    int first_location = alphabet.find(first_letter);
    int first_row = first_location/5;
    int first_col = first_location%5;
    cout << first_location << endl;
    cout << first_row << endl;
    cout << first_col << endl;
    cout << endl;

    //cout << first_location << " " << first_row << " " << first_col << " " << first_new_index << endl;

    int second_location = alphabet.find(second_letter);
    int second_row = second_location/5;
    int second_col = second_location%5;
    cout << second_location << endl;
    cout << second_row << endl;
    cout << second_col << endl;
    cout << endl;


    int first_new_index = first_row * 5 + second_col;
    int second_new_index = second_row * 5 + first_col;
    cout << first_new_index << endl;
    cout << second_new_index << endl;
    cout << endl;

    result += block1[first_new_index];
    cout << result << endl;
    result += block2[second_new_index];
    cout << result << endl;

    return result;
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

    //here is some function testing, not included in mimir submission

    //clean string
    string s = "Hello World"; /*
    string clean = clean_string(s);
    cout << clean << endl; */

    //create encoding
    string result = create_encoding("example");

    //encode_digraph
    string first_keyword = create_encoding("example");
    string second_keyword = create_encoding("keyword");
    result = encode_digraph("he", first_keyword, second_keyword);
    cout << result << endl;

    return 0;
}
