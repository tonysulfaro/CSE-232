#include <iostream>
using std::ostream;
#include <string>
using std::string;
#include <vector>
using std::vector;
#include <utility>
using std::pair; using std::make_pair;
#include <initializer_list>
using std::initializer_list;

#include "proj09_mapset.h"

//default constructor
MapSet::MapSet(initializer_list<pair<string, long> > data_list){
	v_ = data_list;
	vector<pair<string, long> >::iterator find_key(string);
}

//mapset size
size_t MapSet::size(){
	size_t amount = 0;

	for(auto element: v_){
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

	return make_pair("", 1);
}

//update map value
bool MapSet::update(string s, long num){

	pair<string,long> item = make_pair(s,num);

	return false;
}

//remove value from map
bool MapSet::remove(string s){
	if(get(s).first != ""){
		v_.erase(v_.find(get(s)));
		return true;
	}
	return false;
}

//add to map if it doesn't exist
bool MapSet::add(pair<string, long> item){
	string s = item.first;
	//if the first element of the pair is null
	//indicates empty pair returned from get method
	if(get(s).first == ""){
		return false;
	}
	else{
		v_.push_back(item); //add item to MapSet structure, should use add tho
		return true;
	}
	return false;
}

//compare items
int MapSet::compare(MapSet &m)
{
	return 0;
}

//join MapSets together via union
MapSet MapSet::mapset_union(MapSet &m)
{
	return m;
}

//join MapSets together via intersection
MapSet MapSet::mapset_intersection(MapSet &m)
{
	return m;
}

//override << operator for printing mapset
ostream &operator<<(ostream &out, MapSet &m)
{
	out << "Hello";
	return out;
}