#include <iostream>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>
#include <fstream>
using std::string; using std::set; using std::map; using std::pair;
using std::ifstream; using std::cout;

//map of a key of ServerName and value of set of UserNames
using ServerData = map<string, set<string>>;
using UserName = const string &;
using ServerName = const string &;

ServerData ParseServerData(const string &fname){

    string line;
    ifstream inFile;

    //error handling
    inFile.open(fname);

    //use add and delete as users are read in
    if (inFile.is_open()){
    while ( getline (inFile,line, ' ')){
      cout << line[0] << '\n';
      cout << line[1] << '\n';
      cout << line[2] << '\n';
    inFile.close();
        }
    }
}

void PrintAll(std::ostream &out, const ServerData &sd){
    cout << "test";
}

/*
If the server exists, it adds un to that server.
If the server does not exist, it is created (added to sd) and the user un is added to that
server. Both of those conditions return true
*/
bool AddConnection(ServerData & sd, ServerName sn, UserName un){

    pair< map<string,set<string>>::iterator, bool> result;

    long key = ServerData.count(ServerName);

    if(key == 0){
        ServerData.insert({sn, set{un}});
    }
    else{
        ServerData[sn].insert(un)
    }
    return false;
}
bool DeleteConnection(ServerData &sd, ServerName sn, UserName un){
    return false;
}

set<string> AllServers(const ServerData &sd);
set<string> AllUsers(const ServerData &sd);
set<string> HasConnections(const ServerData &sd, UserName un);
set<string> HasUsers(const ServerData &sd, ServerName sn);

void BalanceServers(ServerData &sd, ServerName sn1, ServerName sn2);
void CleanAndBalance(ServerData &sd);
