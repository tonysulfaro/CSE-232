#ifndef PLAYER
#define PLAYER

#include<string>
using std::string;
#include "proj08_market.h"

struct Player {
  double cash;
  map<string, long > stocks;
  
  Player() = default;
  Player(double c) : cash(c) {} ;
  
  bool buy(Market &, string, long, long);
  bool sell(Market &, string, long, long);
  string to_str();
  Player combine(Player& p2);
};



#endif
