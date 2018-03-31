#include <iostream>
using std::ostream;
#include <string>
using std::string;
#include <vector>
using std::vector;
#include <utility>
using std::pair;
#include <initializer_list>
using std::initializer_list;

#include "proj09_mapset.h"

/*default constructor
MapSet::MapSet(initializer_list<pair<string, long>> data_list)
{
} */

//update map
bool MapSet::update(string name, long num)
{
	return false;
}

//remove a string
bool MapSet::remove(string name)
{
	return false;
}

//add to map
bool MapSet::add(pair<string, long> items)
{
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