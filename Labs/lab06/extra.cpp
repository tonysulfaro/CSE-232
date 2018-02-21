#include<vector>
#include<string>
using std::vector;
using std::string;

string my_fun(const vector<string>& v){
    string result="";
    for(auto element : v)
        result += element[0];
    return result;
}
