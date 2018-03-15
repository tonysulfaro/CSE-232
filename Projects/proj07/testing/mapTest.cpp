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

    map<string, set<string>> ServerData;

    //user ServerData
    string sn = "hal";
    string un = "bob";

    long key = ServerData.count(sn);
    cout << key << endl;

    if(key == 0){
        //make new server entry
        ServerData[sn].insert(un);
        key = ServerData.count(sn);
        cout << key << endl;
    }
    ServerData["hal"].insert("another person");
    auto keyPair = ServerData.find(sn);
    set <string> userNames = keyPair -> second;
    pair <string, set<string>> pair_thing = {sn ,userNames };
    for(auto element: userNames){
        cout << sn << endl;
        cout << element << endl;
    }

    /*
    else{
        //assuming there is a key
        auto map_element = ServerData.find(key);
        set <string> users = map_element -> second;
        pair <string, set<string>> pair_thing = {sn, users};
        ServerData.insert(pair_thing);
    }
*/
    return 0;
}
