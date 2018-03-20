
#include<iostream>
using std::cout; using std::endl;
#include<algorithm>
using std::copy;
#include<iterator>
using std::ostream_iterator;
#include<sstream>
using std::ostringstream;
#include<iomanip>
using std::boolalpha; using std::fixed; using std::setprecision;
#include<cassert>

#include "proj08_market.h"
#include "proj08_player.h"

int next_date(int d){
  return d+1;
}

int main(){
  Market mark("dow.txt");
  // if you want to dump the stocks map, uncomment the code below
  // transform(mark.stocks.begin(), mark.stocks.end(), ostream_iterator<string>(cout, ", "),
  // 	    [](pair<long, vector<double>> p){
  // 	      ostringstream oss;
  // 	      oss << p.first;
  // 	      for(auto e : p.second)
  // 		oss << e << ", ";
  // 	      oss << "\n";
  // 	      return oss.str();
  // 	    }
  // 	    );
  
  cout << fixed << setprecision(2);
  cout << boolalpha;
  
  double price;
  price = mark.get_price("AA", 20120831);
  assert(price == 8.53); 
  price = mark.get_price("XOM", 20060927);
  assert(price == 58.82);
  price = mark.get_price("ZZZ", 20120801); // bad symbol
  assert(price == -1.0);
  price = mark.get_price("AA", 19990101); // bad date
  assert(price == -1.0);

  Player p1(1000);
  Player p2(1000);
  bool result;

  double delta = 0.05;
  result = p1.buy(mark, "IBM", 20120831, 5);
  assert(result == true);
  assert((p1.cash < (25.75 + delta)) && (p1.cash > (25.75 - delta)));
  assert(p1.stocks["IBM"] == 5);

  result = p1.sell(mark, "IBM", 20120831, 5);
  assert(result == true);
  assert((p1.cash < (1000 + delta)) && (p1.cash > (1000 - delta)));

  result = p2.buy(mark, "AA", 20010614, 25);
  assert(result == true);
  assert((p2.cash < (219 + delta)) && (p2.cash > (219 - delta)));
  assert(p2.stocks["AA"] == 25);

  // not enough cash
  result = p1.buy(mark, "AA", 20120831, 1000);
  assert(result == false);
  assert((p1.cash < (1000 + delta)) && (p1.cash > (1000 - delta)));

  // bad date
  result = p1.buy(mark, "AA", 21120831, 10);
  assert(result == false);
  assert(p1.cash == 1000);

  // don't have any of this
  result = p1.sell(mark, "AA", 20010614, 25);
  assert(result == false);
  assert((p1.cash < (1000 + delta)) && (p1.cash > (1000 - delta)));

  // don't have that much
  result = p2.sell(mark, "AA",  20010614, 50);
  assert(result == false);
  assert((p2.cash < (219 + delta)) && (p2.cash > (219 - delta)));

  p2.buy(mark, "XOM", 20010614, 1);

  // p2:184.57,AA:25,XOM:1
  cout << "p2:"<<p2.to_str() << endl;
  // p1:1000.00
  cout << "p1:"<<p1.to_str()<<endl;

  // 31.55 14.99
  pair<double,double> pr = mark.high_low_year(2009, "DIS");
  cout << "High:"<<pr.first<<", Low:"<<pr.second<<endl;

  // -1.0, -1.0
  pr = mark.high_low_year(2009, "ZZZ");
  cout << "High:"<<pr.first<<", Low:"<<pr.second<<endl;  

  Player p3(1000);
  Player p4(1000);
  p3.buy(mark,"AA",20120831,5);
  p3.buy(mark,"AXP",20120831,5);
  p4.buy(mark, "BA",20120831,10);
  auto p = p3.combine(p4);
  // 0.00
  cout << p3.to_str() << endl;
  // 0.00
  cout << p4.to_str() << endl;
  // 952.85,AA:5,AXP:5,BA:10
  cout << p.to_str() << endl;
}
