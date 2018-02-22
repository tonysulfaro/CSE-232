#include<iostream>
using std::cout; using std::cin; using std::endl; using std::boolalpha;
#include<string>
using std::string; using std::to_string; using std::tolower;
#include<cmath>
#include <locale>
using std::tolower;
#include "proj05_functions.h"

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

    //decode_digraph
    first_keyword = create_encoding("example");
    second_keyword = create_encoding("keyword");
    result = decode_digraph("fy", first_keyword, second_keyword);
    cout << result << endl;

    return 0;
}
