#include<iostream>
using std::cout; using std::endl; using std::boolalpha;
#include<string>
using std::string;
#include<sstream>
using std::ostringstream;

#include "proj11_mapset.h"

int main (){

	cout << boolalpha;
	Node<string,long> n1("bill", 2);
	cout << n1 << endl; 
	Node<string,long> n2("fred", 3);
	cout << (n1 == n2) <<":"<<(n1 < n2) << endl;
	MapSet<string,long> ms({ {"bill", 1}, {"fred", 2}, {"alan", 3}, {"bob", 4} });
	cout << ms << endl;
	MapSet<string, long> ms_copy(ms);

	cout << "ms:"<<ms<<endl;
	cout << "add ed: " << ms.add({"ed", 5}) << endl;
	cout << "add bob: " << ms.add({"bob", 5}) << endl;
	cout << "ms: " << ms << endl;

	n1 = ms.get("fred");
	cout << "get fred:" << n1 << endl;
	n2 = ms.get("irving");
	cout << "get irving:"<< n2 << endl;
	
	cout << "bob update:" << ms.update("bob", 100) << endl; //problem
	cout << "bob updated: " << ms << endl;
	cout <<  "george update:" << ms.update("george", 10) << endl;
	
	cout << "ms: " << ms << endl;
	cout << "copy:" << ms_copy << endl;
	
	cout << "remove fred: " << ms_copy.remove("fred") << endl;
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

	MapSet<string,long> mtest({ {"z",1},{"e",2},{"x",3}, {"q", 4} });
	cout << "Mtest:"<<mtest << endl;
	Node<string,long> ntest;
	ntest = mtest.get("m");
	cout << "test1:"
		<< mtest.get("m")
		<< endl;
	Node<string,long>ntest2 = mtest.get("q");
	cout << "test2:"<< ntest2 << endl;

	// different types
	
	MapSet<long,string> msl1( {  {4, "bob"}, {1, "bill"}, {3, "alan"}, {2, "fred"} } );
	cout << "msl1: "<<msl1<<endl;

	MapSet<long,string>msl1_copy(msl1);
	cout << "ml1_copy: "<<msl1_copy<<endl;
  
}

