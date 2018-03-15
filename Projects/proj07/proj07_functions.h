#ifndef _MSCSERV_H_
#define _MSCSERV_H_

#include <iostream>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>
#include <fstream>
using std::string; using std::set; using std::map; using std::pair;
using std::ifstream; using std::cout; using std::endl; using std::ostream;

using ServerData = map<string, set<string>>;

using UserName = const string &;
using ServerName = const string &;

ServerData ParseServerData(const string &);
void PrintAll(ostream &, const ServerData &);
bool AddConnection(ServerData &, ServerName, UserName);
bool DeleteConnection(ServerData &, ServerName, UserName);
set<string> AllServers(const ServerData &);
set<string> AllUsers(const ServerData &);
set<string> HasConnections(const ServerData &, UserName);
set<string> HasUsers(const ServerData &, ServerName);
void BalanceServers(ServerData &, ServerName, ServerName);
void CleanAndBalance(ServerData &);

#endif
