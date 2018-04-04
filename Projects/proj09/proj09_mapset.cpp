//iostreams
#include <iostream>
using std::ostream;
#include<sstream>
using std::ostringstream;
//types
#include <string>
using std::string;
#include <vector>
using std::vector; using std::iterator;
#include <initializer_list>
using std::initializer_list;
//stl algorithims
#include <utility>
using std::pair; using std::make_pair;
#include<algorithm>
using std::copy; using std::lower_bound;

//debugging
using std::cout; using std::endl;

#include "proj09_mapset.h"

//constructor with list param
MapSet::MapSet(initializer_list<pair<string, long> > data_list){
	for(auto element: data_list){ //have to use add on every item to keep it in order
		add(element);
	}
	vector<pair<string, long> >::iterator find_key(string);
}

//find key from string, return vector iterator of where to insert pair
vector<pair<string, long> >::iterator MapSet::find_key(string s){

	pair<string, long> item = get(s);
	return lower_bound(v_.begin(), v_.end(), item);
}

//get mapset size
size_t MapSet::size(){
	size_t amount = 0;

	for(auto element: v_){ //count all pairs
		amount++;
	}
	return amount;
}

//get pair from map
pair<string, long> MapSet::get(string s){

	for(auto element: v_){
		string pair_string = element.first;
		long pair_long = element.second;

		//return pair after finding string matches
		if(s == pair_string){
			return make_pair(pair_string, pair_long);
		}
	}
	return make_pair("", 0);
}

//update map value
bool MapSet::update(string s, long num){

	pair<string,long> item = make_pair(s,num);

	if(get(s).first != ""){ //if pair exists then modify it
		remove(s);
		add(item);
		return true;
	}
	return false;
}

//remove value from vector
bool MapSet::remove(string s){

	vector<pair<string, long> >::iterator vec_index = find_key(s);

	if(get(s).first != ""){
		v_.erase(vec_index); //remove item from vector if it exists
		return true;
	}
	return false;
}

//add to map if it doesn't exist
bool MapSet::add(pair<string, long> item){

	string s = item.first;
	//if the first element of the pair is null
	if(get(s).first == ""){ 	//indicates key not in there yet
		vector<pair<string, long> >::iterator itr = lower_bound(v_.begin(), v_.end(), item);
		v_.insert(itr, item);
		return true;
	}
	return false;
}

//compare items
int MapSet::compare(MapSet &m){
	
	long smaller_size = 0;

	(size()<m.size()) ? (smaller_size = size()):(smaller_size = m.size());

	//determines if any values are not equal
	for(int i = 0; i < smaller_size; i++){ //through both up to smallest size
		if(v_[i].first != m.v_[i].first){ //if elements differ
			if(v_[i].first > m.v_[i].first){ //compare first strings of set that differ
				return 1; //calling is bigger
			}
			return -1; //param is bigger
		}
	}

	if(size()>m.size()){ //calling is bigger
		return 1;
	}
	else if(size() == m.size()){ //if they are the same set
		return 0;
	}

	return -1; //param is bigger
}

//join MapSets together via union
MapSet MapSet::mapset_union(MapSet &m){

	//basically tries to add all entries, duplicate keys ignored, calling list added first
	MapSet result;
	for(auto pair: v_){
		result.add(pair);
	}
	for(auto pair: m.v_){
		result.add(pair);
	}
	return result;
}

//join MapSets together via intersection
MapSet MapSet::mapset_intersection(MapSet &m){

	MapSet result;

	//compare all set values to each other
	for(auto pair: v_){
		for(auto param_pair: m.v_){
			string s = pair.first;
			string param_s = param_pair.first;
			if(s == param_s){ //pair in both
				result.add(pair);
			}
		}
	}
	return result;
}

//override << operator for printing mapset
ostream &operator<<(ostream &out, MapSet &m){

	ostringstream oss;

	for(auto element: m.v_){
		string name = element.first;
		long num = element.second;

		oss << name << ":" << num << ", ";
	}
	string s = oss.str();
    s = s.substr(0,s.size()-2); //remove trailing comma
    out << s;
	return out;
}