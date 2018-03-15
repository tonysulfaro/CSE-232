#include <iostream>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>
#include <fstream>
using std::string; using std::set; using std::map; using std::pair;
using std::ifstream; using std::cout; using std::endl;

#include "proj07_functions.h"

int main() {

  auto server_data = ParseServerData("input.txt");
  cout << "Output"<<endl;;
  PrintAll(cout,server_data);
  cout << endl;

  set<string> servers = AllServers(server_data);
  cout << "Server Size:"<< servers.size() << endl;
  set<string> users = AllUsers(server_data);
  cout << "User Size:" << users.size() << endl;
/* should print
arctic : alice fedor jose matus
baron : alice bob dhruv lily loki sonam thor
rusty : alice gigi
*/
  cout << "Balance "<<endl;
  BalanceServers(server_data,"s1","s2");

  PrintAll(cout,server_data);
/* should print
arctic : alice bob dhruv fedor jose lily
baron : alice loki matus sonam thor
rusty : alice gigi
*/
  cout << "Clean and Balance"<<endl;
  CleanAndBalance(server_data);

  PrintAll(cout,server_data);
/* should print
arctic : alice fedor lily sonam
baron : bob gigi loki thor
rusty : dhruv jose matus
*/

}
