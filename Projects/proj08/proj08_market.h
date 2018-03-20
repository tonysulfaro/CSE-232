#ifndef MARKET
#define MARKET

#include<map>
using std::map;
#include<vector>
using std::vector;
#include<string>
using std::string;
#include<utility>
using std::pair;

struct Market{
  string file_name;
  vector<string> symbol_list={"AA","AXP","BA","BAC","CAT","CSCO","CVX","DD",
			     "DIS","GE","HD","HPQ","IBM","INTC","JNJ","JPM",
			     "KFT","KO","MCD","MMM","MRK","MSFT","PFE",
			     "PG","T","TRV","UTX","VZ","WMT","XOM"};
  map<long, vector<double>> stocks;

  Market()=default;
  Market(string s);

  double get_price(string, long) const;
  pair<double, double> high_low_year(long year, string symbol);
};

#endif
