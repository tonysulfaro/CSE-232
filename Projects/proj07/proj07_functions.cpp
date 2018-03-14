#include <iostream>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>
#include <fstream>

//map of a key of ServerName and value of set of UserNames
using ServerData = std::map<std::string, std::set<std::string>>;

using UserName = const std::string &;
using ServerName = const std::string &;

ServerData ParseServerData(const std::string &);
void PrintAll(std::ostream &, const ServerData &);

/*
If the server exists, it adds un to that server.
If the server does not exist, it is created (added to sd) and the user un is added to that
server. Both of those conditions return true
*/
bool AddConnection(ServerData &, ServerName, UserName){

    pair< map<ServerName, UserName>::iterator, bool > result;
    ServerData.insert({ServerName, UserName});
    return false;
}
bool DeleteConnection(ServerData &, ServerName, UserName);
std::set<std::string> AllServers(const ServerData &);
std::set<std::string> AllUsers(const ServerData &);
std::set<std::string> HasConnections(const ServerData &, UserName);
std::set<std::string> HasUsers(const ServerData &, ServerName);
void BalanceServers(ServerData &, ServerName, ServerName);
void CleanAndBalance(ServerData &);
