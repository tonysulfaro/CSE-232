#include<iostream>
using std::cout; using std::cin; using std::endl; using std::boolalpha;
#include<string>
using std::string; using std::to_string;
#include<cmath>
#include <locale>
using std::tolower;

//not needed for now, we will see
//const string alphabet = "0123456789abcdefghijklmnopqrstuvwxyz";

//clean string of all characters
string clean_string(string s){
    string result;
    s = std::tolower(s);

    for(auto ch: s){
        if(ch >= 'a' && ch <= 'z'){
            result += ch;
            cout << ch << endl;
        }
    }
    return result;
}

//create dat encoding to make it mysterious
string create_encoding(string key){
    string keyword;


    return keyword;
}

//generate that board son
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

    return encoding;
}

//decrypt it
string decode(string msg, string key1, string key2){
    string decoding;

    return decoding;
}

int main(){

    string s = "lksjdflkjde333399,x,33'kkd";
    string result = clean_string(s);
    cout << result << endl;

    return 0;
}
