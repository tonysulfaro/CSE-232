#include<iostream>
using std::cout; using std::cin; using std::endl; using std::boolalpha;
#include<string>
using std::string; using std::to_string; using std::tolower;
#include<cmath>
#include <locale>
using std::tolower;

//not needed for now, we will see
const string alphabet = "abcdefghijklmnoprstuvwxyz"; //without 'q'

//clean string of all characters
string clean_string(string s){
    string result;


    for(auto ch: s){
        if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')){
            result += tolower(ch);
        }
    }
    return result;
}

//create dat encoding to make it mysterious
string create_encoding(string key){
    string keyword;

    for(auto ch: key){
        if(keyword.find(ch)==-1 and alphabet.find(ch)!= -1){
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

    /*  Location information:
        row = index/5 (integer division)
        col = index %5
        index = row * 5 + col */

    int first_location = alphabet.find(first_letter);
    int first_row = first_location/5;
    int first_col = first_location%5;

    int second_location = alphabet.find(second_letter);
    int second_row = second_location/5;
    int second_col = second_location%5;

    //get new indexes from blocks
    int first_new_index = first_row * 5 + second_col;
    int second_new_index = second_row * 5 + first_col;

    result += block1[first_new_index];
    result += block2[second_new_index];

    return result;
}

//decode it
string decode_digraph(string dg, string block1, string block2){
    string result;

    char first_letter = dg[0];
    char second_letter = dg[1];

    /*  Location information:
        row = index/5 (integer division)
        col = index %5
        index = row * 5 + col */

    int first_location = block1.find(first_letter);
    int first_row = first_location/5;
    int first_col = first_location%5;

    int second_location = block2.find(second_letter);
    int second_row = second_location/5;
    int second_col = second_location%5;

    //get new indexes from blocks
    int first_new_index = first_row * 5 + second_col;
    int second_new_index = second_row * 5 + first_col;

    result += alphabet[first_new_index];
    result += alphabet[second_new_index];

    return result;
}

//encode it up with basically SHA512
string encode(string msg, string key1, string key2){
    string result;

    msg = clean_string(msg);

    string encode1 = create_encoding(key1);
    string encode2 = create_encoding(key2);

    for(int i = 0; i<= msg.size()-1; i+=2){
        string pair;
        cout << msg[i] << msg[i+1] << endl;
        pair += msg[i];
        pair += msg[i+1];

        if(pair.size() == 1){
            pair += 'x';
        }

        result += encode_digraph(pair,encode1,encode2);

    }

    return result;
}

//decrypt it
string decode(string msg, string key1, string key2){
    string result;

    msg = clean_string(msg);

    string encode1 = create_encoding(key1);
    string encode2 = create_encoding(key2);

    for(int i = 0; i<= msg.size()-1; i+=2){
        string pair;
        cout << msg[i] << msg[i+1] << endl;
        pair += msg[i];
        pair += msg[i+1];

        if(pair.size() == 1){
            pair += 'x';
        }

        result += decode_digraph(pair,encode1,encode2);

    }

    return result;
}
