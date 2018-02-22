#ifndef PROJ05_FOURSQUARE
#define PROJ05_FOURSQUARE

#include<iostream>
using std::cout; using std::cin; using std::endl; using std::boolalpha;
#include<string>
using std::string; using std::to_string; using std::tolower;
#include<cmath>
#include <locale>
using std::tolower;

string clean_string(string s);
string create_encoding(string key);
string encode_digraph(string dg, string block1, string block2);
string decode_digraph(string dg, string block1, string block2);
string encode(string msg, string key1, string key2);
string decode(string msg, string key1, string key2);

#endif
