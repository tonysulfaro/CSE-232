#include <iostream>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>
#include <fstream>
using std::string; using std::set; using std::map; using std::pair;
using std::ifstream; using std::cout; using std:: endl;

int main(){

    string line;
    ifstream inFile;
    inFile.open("input.txt");
    int i = 0;

    //use add and delete as users are read in
    if (inFile.is_open()){
        while ( getline (inFile,line,' ')){
            cout << line << " ";
            cout << ":";
            if(i == 3){
                cout << i ;
                i=0;
            }
            i++;
        }
        inFile.close();
    }
    return 0;
}
