#ifndef _MSCSERV_H_
#define _MSCSERV_H_

#include <iostream>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>
#include <fstream>

using ServerData = std::map<std::string, std::set<std::string>>;

using UserName = const std::string &;
using ServerName = const std::string &;

ServerData ParseServerData(const std::string &);
void PrintAll(std::ostream &, const ServerData &);
bool AddConnection(ServerData &, ServerName, UserName);
bool DeleteConnection(ServerData &, ServerName, UserName);
std::set<std::string> AllServers(const ServerData &);
std::set<std::string> AllUsers(const ServerData &);
std::set<std::string> HasConnections(const ServerData &, UserName);
std::set<std::string> HasUsers(const ServerData &, ServerName);
void BalanceServers(ServerData &, ServerName, ServerName);
void CleanAndBalance(ServerData &);

#endif
