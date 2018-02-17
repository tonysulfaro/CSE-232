#ifndef PROJ05_FOURSQUARE
#define PROJ05_FOURSQUARE

#include<string>
using std:: string;

string clean_string(string s);
string create_encoding(string key);
string encode_digraph(string dg, string block1, string block2);
string decode_digraph(string dg, string block1, string block2);
string encode(string msg, string key1, string key2);
string decode(string msg, string key1, string key2);

#endif
