#include <iostream>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>
using std::vector;
#include <fstream>
#include <algorithm>
//dependances for data structure
using std::string; using std::set; using std::map; using std::pair;
using std::ifstream; using std::cout; using std::endl; using std::to_string;
//set ops and exceptions
using std::set_intersection; using std::set_symmetric_difference;
using std::invalid_argument; using std::transform;

//define types for ServerData data structure
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

//delete person from server
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
    //this is a ton of spaghetti im so sorry to whoever has to read this
    if (inFile.is_open()){
        while (inFile >> line){ //each name/command one at a time
            i++;
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
                //reset temp variables
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

//print entire map
void PrintAll(std::ostream &out, const ServerData &sd){

    string s;
    //iterate over entire map
    for(auto server: sd){
        string server_name = server.first;
        set<string> user_names = server.second;
        out << server_name << " : ";
        //print out user names per server
        for(auto name: user_names){
            s += name; //i know to use ostream but it wasn't cooperating
            s+= " ";
        }
        //remove last space from string
        s = s.substr(0,s.size()-1);
        out << s;
        out << '\n';
        s = "";
    }
}

//returns set of all servers in map
set<string> AllServers(const ServerData &sd){

    set<string> servers;
    //find all the servers and add them into set
    for(auto server: sd){
        string server_name = server.first;
        servers.insert(server_name);
    }
    return servers;
}

//returns set of all users in map
set<string> AllUsers(const ServerData &sd){

    set<string> users;
    //find all users in every sever
    for(auto server: sd){
        //ectract user list from server entry
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
    //finds servers where the user is and adds them to the list
    for(auto server: sd){
        //extract name and user list from server data
        string server_name = server.first;
        set<string> user_list = server.second;
        for(auto user: user_list){
            //find server user is in
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
    //finds a server and returns its user list
    for(auto server: sd){
        //seperate elements from server pair
        string server_name = server.first;
        set<string> user_list = server.second;
        if(server_name == sn){
            //add data from user list
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
    int i = 0;
    //move users to new homes in server
    int move_size = move_users.size();
    int break_point = move_size - (move_size/2);
    for(auto user: move_users){
        (i < break_point) ? (s1_users.insert(user)):(s2_users.insert(user));
        i++;
    }
    //modify map of changes
    sd[sn1] = s1_users;
    sd[sn2] = s2_users;
}

//clean and balance server load
void CleanAndBalance(ServerData &sd){

    set<string> unique_users = AllUsers(sd);

    int server_count = 0;
    set<string> server_list;
    //count and add server names to list
    for(auto server_data: sd){
        string server_name = server_data.first;
        server_list.insert(server_name);
        server_count ++;
        sd[server_name] = {};
    }
    //move users in round robin way
    while(unique_users.size()>0){
        //some good iterator action from the video
        //basicaly take the user_list then put them in a list then remove them one by one
        for(set<string>::iterator i=server_list.begin(); i != server_list.end(); i++){
            string temp_user = *unique_users.begin();
            //insert then remove user from user list
            sd[*i].insert(temp_user);
            unique_users.erase(temp_user);
            if(unique_users.size() == 0){
                break;
            }
        }
    }
}
