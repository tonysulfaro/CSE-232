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
#include<algorithm>
using std::sort; using std::lower_bound;
#include<sstream>
using std::ostringstream;


//
// Node
//
template<typename K, typename V>
struct Node {
  K first;
  V second;
  Node() = default;
  Node(K,V);
  bool operator<(const Node&) const;
  bool operator==(const Node&) const;
  friend ostream& operator<<(ostream &out, const Node &n){

    // WRITE YOUR CODE HERE!!!
    
    return out;
  }
};

template<typename K, typename V>
Node<K,V>::Node(K key, V value){

}

template<typename K, typename V>
bool Node<K,V>::operator<(const Node &n) const{

}

template<typename K, typename V>
bool Node<K,V>::operator==(const Node &n) const{
	return  false;
}

//
// MapSet
// 
template<typename K, typename V>
class MapSet{
 private:
  Node<K,V>* ary_;
  size_t last_;
  size_t capacity_;
  Node<K,V>* find_key(K);
  void grow ();
 public:
  MapSet(int sz = 2);
  MapSet(initializer_list< Node<K,V> >);
  MapSet (const MapSet&);
  MapSet operator=(MapSet);
  ~MapSet();
  size_t size();
  bool remove (K);  
  bool add(Node<K,V>);
  Node<K,V> get(K);
  bool update(K,V);  
  int compare(MapSet&);
  MapSet mapset_union (MapSet&);
  MapSet mapset_intersection(MapSet&);

  friend ostream& operator<<(ostream &out, const MapSet &ms){

    // WRITE YOUR CODE HERE!!!
    
    return out;
  }  
};

template<typename K, typename V>
MapSet<K,V>::MapSet(int capacity){

}

template<typename K, typename V>
MapSet<K,V>::MapSet(initializer_list< Node<K,V> > il){

}

template<typename K, typename V>
MapSet<K,V>::MapSet(const MapSet &ms){

}

// copy and swap
template<typename K, typename V>
MapSet<K,V> MapSet<K,V>::operator=(MapSet<K,V> ms){

}

template<typename K, typename V>
MapSet<K,V>::~MapSet(){

}

template<typename K, typename V>
size_t MapSet<K,V>::size(){

}

template<typename K, typename V>
void MapSet<K,V>::grow(){

}

template<typename K, typename V>
Node<K,V>* MapSet<K,V>::find_key(K key){

}

template<typename K, typename V>
bool MapSet<K,V>::add(Node<K,V> n){

}

template<typename K, typename V>
bool MapSet<K,V>::remove(K key){

}

template<typename K, typename V>
Node<K,V> MapSet<K,V>::get(K key){

}

template<typename K, typename V>
bool MapSet<K,V>::update(K key, V value){

}

template<typename K, typename V>
int MapSet<K,V>::compare(MapSet &ms){

}

template<typename K, typename V>
MapSet<K,V> MapSet<K,V>::mapset_union(MapSet<K,V> &ms){

}

template<typename K, typename V>
MapSet<K,V> MapSet<K,V>::mapset_intersection(MapSet<K,V> &ms){

}

#endif
  
