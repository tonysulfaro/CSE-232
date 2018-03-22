#include<map>
using std::map;
#include<vector>
using std::vector;
#include<string>
using std::string;
#include<utility>
using std::pair;
//for output
#include<sstream>
using std::string;
using std::ostringstream;

//debugging
#include<iostream>
using std::cout; using std::endl;

#include "proj08_player.h"

//player constructor

//buy a stock and add to map
bool Player::buy(Market &m, string stock, long date, long quantity){

    double stock_price = m.get_price(stock, date);
    double stock_cost = stock_price * quantity;

    //cout << "player cash: " << cash << endl;
    //cout << "stock price: " << stock_price << endl;
    //cout << "stock cost: " << stock_cost << endl;

    if(stock_cost <= cash && stock_price > 0.0){
        cash -= stock_cost;
        stocks[stock] += quantity;
        return true;
    }
    return false;
}

//sell a stock and remove from map
bool Player::sell(Market &m, string stock, long date, long quantity){

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

//return string
string Player::to_str(){
	ostringstream oss;
    oss << cash << ",";
    for(auto e: stocks)
    oss << e.first << ":" << e.second << ",";
    return oss.str();
}

//combine both players
Player Player::combine(Player & p2){
    return p2;
}