#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "proj07_functions.h"

int main() {

  auto server_data = ParseServerData("input.txt");
  std::cout << "Output"<<std::endl;;
  PrintAll(std::cout,server_data);
  std::cout << std::endl;

  std::set<std::string> servers = AllServers(server_data);
  std::cout << "Server Size:"<< servers.size() << std::endl;
  std::set<std::string> users = AllUsers(server_data);
  std::cout << "User Size:" << users.size() << std::endl;
/* should print
arctic : alice fedor jose matus
baron : alice bob dhruv lily loki sonam thor
rusty : alice gigi
*/
  std::cout << "Balance "<<std::endl;
  BalanceServers(server_data,"arctic","baron");

  PrintAll(std::cout,server_data);
/* should print
arctic : alice bob dhruv fedor jose lily
baron : alice loki matus sonam thor
rusty : alice gigi
*/
  std::cout << "Clean and Balance"<<std::endl;
  CleanAndBalance(server_data);

  PrintAll(std::cout,server_data);
/* should print
arctic : alice fedor lily sonam
baron : bob gigi loki thor
rusty : dhruv jose matus
*/

}
