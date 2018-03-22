#include<map>
using std::map;
#include<vector>
using std::vector;
#include<string>
using std::string;
#include<utility>
using std::pair;

#include "proj08_player.h"

//buy a stock and add to map
bool Player::buy(Market &m, string stock, long date, long quantity){
    return true;
}

//sell a stock and remove from map
bool Player::sell(Market &m, string stock, long date, long quantity){
    return true;
}

//return string
string Player::to_str(){
    return "Test";
}

//combine both players
Player Player::combine(Player & p2){
    return p2;
}