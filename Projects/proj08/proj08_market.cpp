#include<map>
using std::map;
#include<vector>
using std::vector;
#include<string>
using std::string; using std::to_string;
#include<utility>
using std::pair; using std::make_pair;
#include<fstream>
using std::ifstream;
#include <sstream>
using std::istringstream;

#include "proj08_market.h"

//constructor for market file
Market::Market(string file){
    file_name = file;

    //read in data and populate map
    ifstream inFile(file_name);
    string line;
    while(getline(inFile,line)){
        istringstream iss (line);

        //get values from stringstream then cast them
        string date;
        string value;
        iss >> date;
        long long_date = stol(date);

        //add long key (date) into map
        stocks.insert({long_date,{}});
        //add stock prices into the double vector
        for(int i = 0; i < symbol_list.size(); i++){
            iss >> value;
            stocks[long_date].push_back(stod(value));
        }
    }
}

//return price of stock if is valid date and valid stock, -1.0 otherwise
double Market::get_price(string stock, long date) const{

    int stock_index = 0;
    //get stock location in price vector
    auto stock_location = find(symbol_list.begin(),symbol_list.end(), stock);
    if(stock_location == symbol_list.end()){ //stock not found
        return -1.0;
    }
    else{
        stock_index = distance(symbol_list.begin(), stock_location); //stock is found and is at index
    }

    //The prices of the 30 stocks on the date (the key)
    for(auto element: stocks){
        long date_entry = element.first;
        vector<double> prices = element.second;
        //if dates match up fetch stock price
        if(date_entry == date){
            return prices[stock_index];
        }
    }
    //base case, stock not found
    return -1.0;
}

//Returns as a pair the high and low for stock
pair<double, double> Market::high_low_year(long year, string symbol){
    //iterate through date entries
    double high = 0.0;
    double low = 99999.0; //would rather use double.maxValue

    //error handling for symbol
    auto stock_location = find(symbol_list.begin(),symbol_list.end(), symbol);
    if(stock_location == symbol_list.end()){ //stock not found
        return make_pair(-1.0,-1.0);
    }

    //iterate over map
    for(auto entry: stocks){
        long date = entry.first;
        long entry_year = date/10000;
        vector<double> prices = entry.second;

        //for specified year
        if(entry_year == year){
            //get price and modify high/low entries
            double stock_price = get_price(symbol, date);
            if(stock_price >= high){
                high = stock_price;
            }
            if(stock_price <= low){
                low = stock_price;
            }
        }
    }
    //error handling for invalid year
    if(high == 0.0){
        return make_pair(-1.0,-1.0);
    }
    //base case
    return make_pair(high, low);
}