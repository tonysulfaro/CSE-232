#include<iostream>
using std::cout; using std::endl; using std::boolalpha;
#include<string>
using std::string;
#include<utility>
using std::pair;
#include<initializer_list>
using std::initializer_list;

#include "proj09_mapset.h"

int main (){
  pair<string,long> itr;
  cout << boolalpha;
  
  MapSet ms ({ {"bill", 1}, {"fred", 2}, {"alan", 3}, {"bob", 4} });
  cout << "Size:"<<ms.size() << endl;

  MapSet ms_copy(ms);

  cout << "ms:"<<ms<<endl;
  cout << "add ed: " << ms.add({"ed", 5}) << endl;
  cout << "add bob: " << ms.add({"bob", 5}) << endl;
  cout << "ms: "<< ms << endl;
  
  cout << "bob update:" << ms.update("bob", 100) << endl;
  cout <<  "george update:" << ms.update("george", 10) << endl;
  cout << "ms: "<< ms << endl;
  cout << "ms_copy: " << ms_copy << endl;

  cout << "remove fred: " << ms_copy.remove("fred") << endl;
  cout << "AFTER REMOVE: " << ms_copy << endl;
  cout << "remove george: " << ms_copy.remove("george") << endl;  

  cout << "ms:"<< ms << endl;  
  cout << "copy:"<< ms_copy << endl;  

  cout << "copy2ms: "<< ms_copy.compare(ms) << endl;
  cout << "ms2copy: "<<ms.compare(ms_copy) << endl;
  cout << "ms2ms: "<<ms.compare(ms) << endl;
  
  auto union_ms = ms.mapset_union(ms_copy);
  cout << "union: " <<union_ms << endl;
  auto intersect_ms = ms.mapset_intersection(ms_copy);
  cout << "intersection: "<< intersect_ms <<endl;

}
  
