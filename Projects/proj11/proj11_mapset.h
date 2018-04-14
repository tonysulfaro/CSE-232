#ifndef MAP_SET
#define MAP_SET

#include<iostream>
using std::ostream;
#include<string>
using std::string;
#include<utility>
using std::pair;
#include<initializer_list>
using std::initializer_list;
#include<sstream>
using std::ostringstream;


//
// Node
//
template<typename K, typename V>
struct Node {
  K first;
  V second;
  Node *next = nullptr;
  
  Node() = default;
  Node(K,V);
  bool operator<(const Node&) const;
  bool operator==(const Node&) const;
  friend ostream& operator<<(ostream &out, const Node &n){
    // YOUR CODE HERE
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

}


//
// MapSet
// 
template<typename K, typename V>
class MapSet{
 private:
  Node<K,V>* head_ = nullptr;
  Node<K,V>* tail_ = nullptr;  
  size_t sz_ = 0;
  SOMETYPE find_key(K);

 public:
  MapSet()=default;
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
    // YOUR CODE HERE
  }  
};

template<typename K, typename V>
  MapSet<K,V>::MapSet(initializer_list< Node<K,V> > il){

}

template<typename K, typename V>
MapSet<K,V>::MapSet(const MapSet &ms){

}

template<typename K, typename V>
MapSet<K,V> MapSet<K,V>::operator=(MapSet ms){

}	

// walk down the list, moving head_ but remember it in to_del
// delete each node in turn, the set head_ and tail_
template<typename K, typename V>
MapSet<K,V>::~MapSet(){

}

template<typename K, typename V>
size_t MapSet<K,V>::size(){

}

template<typename K, typename V>
SOMETYPE MapSet<K,V>::find_key(K key){

}

template<typename K, typename V>
bool MapSet<K,V>::add(Node<K,V> n){

}

template<typename K, typename V>
bool MapSet<K,V>::remove(K key){
 
}

template<typename K, typename V>
Node<K,V> MapSet<K,V>::get(K key){


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
  