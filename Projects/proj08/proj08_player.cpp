#include<map>
using std::map;
#include<vector>
using std::vector;
#include<string>
using std::string;
#include<utility>
using std::pair;
//for output
#include<iomanip>
using std::string; using std::fixed; using std::setprecision;
#include<sstream>
using std::ostringstream;

#include "proj08_player.h"

//buy a stock and add to map
bool Player::buy(Market &m, string stock, long date, long quantity){

    //get working variables
    double stock_price = m.get_price(stock, date);
    double stock_cost = stock_price * quantity;

    //error handling
    if(stock_cost <= cash && stock_price > 0.0){
        cash -= stock_cost;
        stocks[stock] += quantity;
        return true;
    }
    return false;
}

//sell a stock and remove from map
bool Player::sell(Market &m, string stock, long date, long quantity){

    //get working variables
    long availible_quantity = stocks[stock];
    double stock_price = m.get_price(stock, date);
    double stock_cost = stock_price * quantity;

    //error handling
    if(availible_quantity >= quantity && stock_price > 0.0){
        cash += stock_cost;
        stocks[stock] -= quantity;
        return true;
    }
    return false;
}

//return player as a string
string Player::to_str(){
	ostringstream oss;
    oss << fixed << setprecision(2) << cash << ","; //print cash amount with two decimal places
    for(auto e: stocks)
    oss << e.first << ":" << e.second << ","; //print out rest of map elements
    return oss.str().substr(0,oss.str().size()-1); //remove trailing comma
}

//combine both players
Player Player::combine(Player & p2){

    //initialize new player and assign attributes
    Player p;
    p.cash += cash;
    p.cash += p2.cash;
    p.stocks = p2.stocks;
    p.stocks.insert(stocks.begin(),stocks.end());

    //remove items from other players
    cash = 0.0;
    stocks = {};
    p2.cash = 0.0;
    p2.stocks = {};

    return p;
}