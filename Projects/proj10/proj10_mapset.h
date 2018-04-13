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
using std::sort; using std::lower_bound; using std::copy;
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
	return (first < n.first);
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
		oss << ms.ary_[i];
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

//mapset constructor with param mapset
template<typename K, typename V>
MapSet<K,V>::MapSet(const MapSet &ms){
	ary_ = ms.ary_;
	last_ = ms.last_;
	capacity_ = ms.capacity_;
}

//assign mapset to another mapset
template<typename K, typename V>
MapSet<K,V> MapSet<K,V>::operator=(MapSet<K,V> ms){
	ary_ = ms.ary_;
	last_ = ms.last_;
	capacity_ = ms.capacity_;
}


//default destructor
template<typename K, typename V>
MapSet<K,V>::~MapSet(){
	delete [] ary_;
}

//mapset size
template<typename K, typename V>
size_t MapSet<K,V>::size(){
	return last_;
}

//increase mapset capacity
template<typename K, typename V>
void MapSet<K,V>::grow(){
	Node<K,V> *new_ary = nullptr;

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

//returns pointer to pair element
template<typename K, typename V>
Node<K,V>* MapSet<K,V>::find_key(K key){

	for(int i = 0; i < last_; i++){

		K item = ary_[i].first;

		if(item == key){
			return *ary_[i];
		}
	}
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

	//new array
	Node<K,V> *new_ary = nullptr; 

	int insert_point =  -1;
	for(int i = 0; i < last_; i ++){
		if(ary_[i].first < n.first){
			insert_point ++;
		}
	}
	copy(ary_, ary_+insert_point, new_ary);
	ary_[insert_point+1] = n;
	copy(ary_+insert_point, ary_+last_, new_ary);
	std::swap(new_ary,ary_);
	delete new_ary;
	last_++;

	return true;
}

//remove item from MapSet
template<typename K, typename V>
bool MapSet<K,V>::remove(K key){

	int remove_index = -1;

	//find where the remove thing is at
	for(int i = 0; i < last_; i++){
		K item = ary_[i].first;
		if(item == key){
			remove_index =  i;
		}
	}

	//item they want to remove isnt in there
	if(remove_index == -1){
		return false;
	}

	Node<K,V> *new_ary = nullptr;

	copy(ary_, ary_+remove_index-1, new_ary);
	copy(ary_+remove_index,ary_+last_, new_ary);
	std::swap(new_ary,ary_);
	delete new_ary;
	return true;
}

//get pair from mapset based on key
template<typename K, typename V>
Node<K,V> MapSet<K,V>::get(K key){

	for(int i = 0; i < last_; i++){
		K pair_key = ary_[i].first;
		if(pair_key == key){
			return ary_[i];
		}
	}

	return Node<K,V>(); //return empty node if not found
}

//update mapset value
template<typename K, typename V>
bool MapSet<K,V>::update(K key, V value){

	bool result = false;
	auto item = Node<K,V>(key, value);
	result = remove(key);
	add(item);
	return result;
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
  
