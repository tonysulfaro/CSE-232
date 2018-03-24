#ifndef MAP_SET
#define MAP_SET

#include<iostream>
using std::ostream;
#include<string>
using std::string;
#include<vector>
using std::vector;
#include<utility>
using std::pair;
#include<initializer_list>
using std::initializer_list;

class MapSet{
 private:
  vector< pair<string,long> > v_;
  vector< pair <string, long> >::iterator find_key(string);
 public:
  MapSet() = default;
  MapSet(initializer_list< pair<string,long> >);

  size_t size();
  pair<string,long> get(string);
  bool update(string,long);
  bool remove (string);
  bool add(pair<string,long>);
  int compare(MapSet&);
  MapSet mapset_union (MapSet&);
  MapSet mapset_intersection(MapSet&);
  friend ostream& operator<<(ostream&, MapSet&);  

};

ostream& operator<<(ostream&, MapSet&);

#endif
  
