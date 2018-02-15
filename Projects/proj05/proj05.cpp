#include<iostream>
using std::cout; using std::cin; using std::endl; using std::boolalpha;
#include<string>
using std::string; using std::to_string;
#include<cmath>

//not needed for now, we will see
//const string alphabet = "0123456789abcdefghijklmnopqrstuvwxyz";

//clean string of all characters
string clean_string(string s){
    string result;

    for(auto ch: s){
        if(ch >= 'a' && ch <= 'z'){
            result += ch;
            cout << ch << endl;
        }
    }

    return result;
}

int main(){

    string s = "lksjdflkjde333399,x,33'kkd";
    string result = clean_string(s);
    cout << result << endl;

    return 0;
}
