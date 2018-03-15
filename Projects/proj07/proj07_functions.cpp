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
    ServerData sd;

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
    return sd;
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
    long key = sd.count(sn);

    //if ServerName not in map
    if(key == 0){
        //make new server entry
        result = sd.insert({sn,{un}});
        return result.second;
    }
    //existing server in map
    else{
        //check if user is already in host
        for(auto person: sd[sn]){
            if(person == un){
                return false;
            }
        }
        //add user into host
        sd[sn].insert(un);
        return true;
    }
    return result.second;
}
bool DeleteConnection(ServerData &sd, ServerName sn, UserName un){

    pair< map<string,set<string>>::iterator, bool> result;
    long key = sd.count(sn);

    //error handling: delete someone from non-existent server
    if(key == 0){
        return false;
    }
    //find the person then eliminate them
    for(auto person: sd[sn]){
        if(person == un){
            sd[sn].erase(un);
            return true;
        }
    }
    //base case
    return false;
}

//returns set of all servers in map
set<string> AllServers(const ServerData &sd){

    set<string> servers;
    //for(auto server: sd){
    //    servers.insert(server);
    //}
    return servers;
}

//returns set of all users in map
set<string> AllUsers(const ServerData &sd){

    set<string> users;
    /*
    for(auto server: sd){
        for(auto user: server){
            users.insert(user);
        }
    }
    */
    return users;
}

//returns set of all servers a user is in
set<string> HasConnections(const ServerData &sd, UserName un){

    set<string> connections;
    /*
    for(auto server: sd){
        for(auto user: server){
            if(user == un){
                connections.insert(server); //this is alot of nesting
            }
        }
    }
    */
    return connections;
}

//returns set of all users in a server
set<string> HasUsers(const ServerData &sd, ServerName sn){

    set<string> userList;
    /*
    for(auto user: sd[sn]){
        userList.insert(user);
    }
    */
    return userList;
}

void BalanceServers(ServerData &sd, ServerName sn1, ServerName sn2){
    cout << "test";
}
void CleanAndBalance(ServerData &sd){
    cout << "test";
}
