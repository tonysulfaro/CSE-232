#include <iostream>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>
using std::vector;
#include <fstream>
#include <algorithm>
using std::string; using std::set; using std::map; using std::pair;
using std::ifstream; using std::cout; using std::endl; using std::to_string;
using std::set_intersection; using std::set_symmetric_difference;
using std::invalid_argument; using std::transform;

//map of a key of ServerName and value of set of UserNames
using ServerData = map<string, set<string>>;
using UserName = const string &;
using ServerName = const string &;

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

//generate map
ServerData ParseServerData(const string &fname){

    string line;
    ifstream inFile(fname);
    ServerData sd;
    int i = 0;
    string user;
    string command;
    string server;
    bool result;

    //error handling for no file found
    if(!inFile){
        throw std::invalid_argument("invalid argument");
    }

    //use add and delete as users are read in
    if (inFile.is_open()){
        while (inFile >> line){ //each name/command one at a time
            i++;
            //cout << "Line: " << line << " I: " << i << '\n';
            //put user into temp variable
            if(i == 1){
                user = line;
            }
            //put command into temp veriable
            else if(i == 2){
                command = line;
                //if command isnt join or leave
                if(command != "join" && command != "leave"){
                    throw std::domain_error("domain error");
                }
            }
            //when there is a user, command, and sever in temp variables
            else if(i == 3){
                server = line;
                if(command == "join"){
                    result = AddConnection(sd, server, user);
                }
                else if(command == "leave"){
                    result = DeleteConnection(sd, server, user);
                }
                i = 0;
                user = "";
                command = "";
                server = "";
            }
        }
        inFile.close();
    }
    return sd;
}

//print entire map_element
void PrintAll(std::ostream &out, const ServerData &sd){
    for(auto server: sd){
        string server_name = server.first;
        set<string> user_names = server.second;
        cout << server_name << " : ";
        for(auto name: user_names){
            cout << name << " ";
        }
        cout << '\n';
    }
}

//returns set of all servers in map
set<string> AllServers(const ServerData &sd){

    set<string> servers;
    for(auto server: sd){
        string server_name = server.first;
        servers.insert(server_name);
    }
    return servers;
}

//returns set of all users in map
set<string> AllUsers(const ServerData &sd){

    set<string> users;
    for(auto server: sd){
        set<string> user_list = server.second;
        for(auto user: user_list){
            users.insert(user);
        }
    }
    return users;
}

//returns set of all servers a user is in
set<string> HasConnections(const ServerData &sd, UserName un){

    set<string> connections;
    for(auto server: sd){
        string server_name = server.first;
        set<string> user_list = server.second;
        for(auto user: user_list){
            if(user == un){
                connections.insert(server_name); //this is alot of nesting
            }
        }
    }
    return connections;
}

//returns set of all users in a server
set<string> HasUsers(const ServerData &sd, ServerName sn){

    set<string> userList;
    for(auto server: sd){
        string server_name = server.first;
        set<string> user_list = server.second;
        if(server_name == sn){
            for(auto user: user_list){
                userList.insert(user);
            }
            continue;
        }
    }
    return userList;
}

void BalanceServers(ServerData &sd, ServerName sn1, ServerName sn2){
    std::ostream_iterator<string> os_itr (cout, ",");
    set<string> s1_users = HasUsers(sd,sn1);
    set<string> s2_users = HasUsers(sd,sn2);

    //users in both servers
    set<string> no_move_users;
    std::set_intersection(s1_users.begin(), s1_users.end(),
                          s2_users.begin(), s2_users.end(),
                          std::inserter(no_move_users,no_move_users.begin()));
    //users in only one server
    set<string> move_users;
    std::set_symmetric_difference(s1_users.begin(), s1_users.end(),
                                  s2_users.begin(), s2_users.end(),
                                  std::inserter(move_users,move_users.begin()));

    //remove users from sets
    s1_users = {};
    s2_users = {};
    for(auto user: no_move_users){
        s1_users.insert(user);
        s2_users.insert(user);
    }

    //move users back to server
    //this one just balances them from one to the other
    int i = 0; /*
    for(auto user: move_users){
        if(i%2 == 0){
            //cout << sn1 << " : " << user << "\n";
            s1_users.insert(user);
        }
        else{
            //cout << sn2 << " : " << user << "\n";
            s2_users.insert(user);
        }
        i++;
    } */
    //move users to new homes in server
    int move_size = move_users.size();
    int break_point = (move_size/2);
    for(auto user: move_users){
        (i <= break_point) ? (s1_users.insert(user)):(s2_users.insert(user));
        i++;
    }
    //modify map of changes
    sd[sn1] = s1_users;
    sd[sn2] = s2_users;
}

//clean and balance server load
void CleanAndBalance(ServerData &sd){
    cout << "test";
}
