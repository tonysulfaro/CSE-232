#ifndef MAP_SET
#define MAP_SET

#include<iostream>
using std::ostream;
#include<string>
using std::string;
#include<vector>
using std::vector;
#include<utility>
using std::pair; using std::make_pair;
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

    out << n.first << ":" << n.second;
    
    return out;
  }
};

//pair constructor
template<typename K, typename V>
Node<K,V>::Node(K key, V value){
	first = key;
	second = value;
}

//which one is greater? for lower_bound
template<typename K, typename V>
bool Node<K,V>::operator<(const Node &n) const{
	return (first == n.first);
}

//if first item in pair are the same
template<typename K, typename V>
bool Node<K,V>::operator==(const Node &n) const{
	return (first == n.first);
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

	ostringstream oss;

    for(int i = 0; i < ms.last_; i++){
		operator<<(out, ms[i]);
		oss << ", ";
	}

	string s = oss.str();
    s = s.substr(0,s.size()-2); //remove trailing comma
    out << s;

    return out;
  }  
};

template<typename K, typename V>
MapSet<K,V>::MapSet(int capacity){
	ary_ = nullptr;
	capacity_ = capacity;
	last_ = 0;
}

template<typename K, typename V>
MapSet<K,V>::MapSet(initializer_list< Node<K,V> > il){
	last_ = il.size();
	capacity_ = il.size();
	ary_ = new Node<K,V>[capacity_]; //new array of nodes
	size_t index = 0;

	//add stuff to array
	for(auto element: il){
		add(element);
	}
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
	Node<K,V> *new_ary;

  if (last_ == 0){
    new_ary = new Node<K,V>[1]{};
    last_ = 0;
	capacity_ = 1;
    // ary_ empty, just assign
    ary_ = new_ary;
  }
  else{
    // use {} to init to default
    new_ary = new Node<K,V>[capacity_ * 2]{};
    copy(ary_, ary_+capacity_, new_ary);
    capacity_ *= 2;
    // stl swap, not Stack swap
    std::swap (new_ary, ary_);
    delete [] new_ary;
  }
}

template<typename K, typename V>
Node<K,V>* MapSet<K,V>::find_key(K key){

}

//add elements to array in order
template<typename K, typename V>
bool MapSet<K,V>::add(Node<K,V> n){

	//entry already in mapset
	for(int i = 0; i < last_; i++){
		K item = ary_[i].first;
		if(item == n.first){
			return false;
		}
	}

	//add new entry into the array
	if(last_ >= capacity_){ //grow if ary_ is too small
		grow();
	}

	auto insert_point = lower_bound(ary_, ary_+last_, n);

	last_++;
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
  
