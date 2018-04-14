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
using std::swap;

//debugging
using std::cout; using std::endl;


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
	last_ = 0;
	capacity_ = il.size();
	ary_ = new Node<K,V>[capacity_]; //new array of nodes

	//add stuff to array
	for(auto element: il){
		cout << "ADDING ELEMENT: " << element << endl;
		add(element);
	}
}

//mapset constructor with param mapset
template<typename K, typename V>
MapSet<K,V>::MapSet(const MapSet &ms){
	
	last_ = ms.last_;
	capacity_ = ms.capacity_;
	ary_ = new Node<K,V>[capacity_];
	copy(ms.ary_,ms.ary_+last_, ary_);
}

//assign mapset to another mapset
template<typename K, typename V>
MapSet<K,V> MapSet<K,V>::operator=(MapSet<K,V> ms){
	swap(this-> last_, ms.last_);
	swap(this-> capacity_, ms.capacity_);
	swap(this-> ary_, ms.ary_);
	return *this;
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
	Node<K,V> *new_ary;

  if (capacity_ == 0){
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

	//cout << "BEFORE GROW" << endl;
	//add new entry into the array
	if(last_ == capacity_){ //grow if ary_ is too small
		grow();
	}
	//cout << "CAPACITY " << capacity_ << endl;
	//cout << "last " << last_ <<endl;

	//new array
	Node<K,V> *new_ary;
	new_ary = new Node<K, V>[capacity_]; 

	//cout << "FIND INSERT POINT" <<endl;

	int insert_point = 0;
	for(int i = 0; i < last_; i++){
		if(ary_[i] < n){
			insert_point ++;
		}
	}
	cout << "INSERT POINT " << insert_point << endl;
	
	//cout << "before copy" << endl;
	


	new_ary[insert_point] = n;
	cout << "ARY add item " << *ary_ << endl;
	last_++;

	//add items before index
	for(int i = 0; i < insert_point; i++){
		new_ary[i] = ary_[i];
	}

	//add items after index
	for(int i = insert_point; i < last_; i++){
		new_ary[i+1] = ary_[i];
	}

	
		


	//copy(ary_, ary_+insert_point, new_ary); 
	/*
	for(int i =0; i < insert_point; i++){
		new_ary[i] = ary_[i];
	} */
	cout << "ARY first copy " << *ary_ << endl;

	//cout << "after first copy" <<endl;
	

	//copy(ary_+insert_point+1, ary_+last_, new_ary);
	//for(int i = insert_point+1; i < last_; i++){
	//	new_ary[i] = ary_[i];
	//}
	cout << "ARY add trailing items " << *ary_ << endl;

	//cout << "after copy" << endl;
	std::swap(new_ary, ary_);
	//cout << "after swap" << endl;
	//cout << "after delete" << endl;
	delete [] new_ary;

	cout << "ARY " << *ary_ << endl;
	cout << "LAST " << last_ << endl;

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
	delete [] new_ary;
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
  
