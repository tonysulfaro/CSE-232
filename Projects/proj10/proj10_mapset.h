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

	//print node	
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

//is calling node < param
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
		size_t capacity_ = 0;
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

	//print mapset out
	friend ostream& operator<<(ostream &out, const MapSet &ms){

		ostringstream oss;

		//iterate over the mapset array
		for(int i = 0; i < ms.last_; i++){
			oss << ms.ary_[i]; //print out the nodes
			oss << ", ";
		}

		string s = oss.str();
		s = s.substr(0,s.size()-2); //remove trailing comma
		out << s;

		return out;
	}  
};

//capacity constructor
//param: 	int capacity
template<typename K, typename V>
MapSet<K,V>::MapSet(int capacity){
	ary_ = new Node<K, V>[capacity];
	capacity_ = capacity;
	last_ = 0;
}

//initializer list mapset constructor
//param: initializer_list il
template<typename K, typename V>
MapSet<K,V>::MapSet(initializer_list< Node<K,V> > il){
	last_ = 0;
	capacity_ = il.size();
	ary_ = new Node<K,V>[capacity_]; //new array of nodes

	//add stuff to array
	for(auto element: il){
		add(element);
	}
}

//mapset 	constructor with param mapset
//param: 	Mapset &ms
template<typename K, typename V>
MapSet<K,V>::MapSet(const MapSet &ms){
	//assign this values to parameter ones
	last_ = ms.last_;
	capacity_ = ms.capacity_;
	ary_ = new Node<K,V>[capacity_];
	copy(ms.ary_,ms.ary_+last_, ary_); //copy ary values to ms.ary
}

//assign mapset to another mapset
template<typename K, typename V>
MapSet<K,V> MapSet<K,V>::operator=(MapSet<K,V> ms){
	//swap values and return this
	swap(this-> last_, ms.last_);
	swap(this-> capacity_, ms.capacity_);
	swap(this-> ary_, ms.ary_);
	return *this;
}


//default destructor
template<typename K, typename V>
MapSet<K,V>::~MapSet(){
	delete [] ary_;
    //capacity_=0;
    //last_=0;
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

	//for empty ary
	if (capacity_ == 0){
		new_ary = new Node<K,V>[1]{};
		last_ = 0;
		capacity_ = 1;
		// ary_ empty, just assign
		std::swap (new_ary, ary_);
		delete [] new_ary;
	}
	//if ary already has values in it
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
//param: K key
//return: Node<K,V>*
template<typename K, typename V>
Node<K,V>* MapSet<K,V>::find_key(K key){

	//iterate over map and find matching keys
	for(int i = 0; i < last_; i++){

		K item = ary_[i].first;

		if(item == key){
			return *ary_[i]; //return node pointer
		}
	}
	return nullptr;
}

//add elements to array in order
//param: 	Node<K,V> n
//return: 	bool
template<typename K, typename V>
bool MapSet<K,V>::add(Node<K,V> n){

	//entry already in mapset
	for(int i =0; i< last_; i++){
		if(ary_[i].first == n.first){
			return false;
		}
	}

	if(last_ == capacity_){ //grow if ary_ is too small
		grow();
	}

	//new array
	Node<K,V> *new_ary;
	new_ary = new Node<K, V>[capacity_]; 

	int insert_point = 0;
	for(int i = 0; i < last_; i++){
		if(ary_[i] < n){
			insert_point ++;
		}
	}
	//insert item to new array
	new_ary[insert_point] = n;
	last_++;

	//add items before index
	for(int i = 0; i < insert_point; i++){
		new_ary[i] = ary_[i];
	}

	//add items after index
	for(int i = insert_point; i < last_-1; i++){
		new_ary[i+1] = ary_[i];
	}

	std::swap(new_ary, ary_);
	delete [] new_ary;

	return true;
}

//remove item from MapSet
//param: 	K key
//return:	bool
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

	//new array to hold elements - remove item
	last_--;
	Node<K,V> *new_ary;
	new_ary = new Node<K,V>[capacity_-1];

	//add everything up to the remove element
	for(int i = 0; i < remove_index; i++){
		new_ary[i] = ary_[i];
	}

	//add everthing after the point
	for(int i = remove_index; i < last_; i++){
		new_ary[i] = ary_[i+1];
	}

	swap(new_ary,ary_);
	delete [] new_ary;
	return true;
}

//get pair from mapset based on key
//param:	K key
//return: 	Node<K,V>
template<typename K, typename V>
Node<K,V> MapSet<K,V>::get(K key){

	//look for matching key in ary_
	for(int i = 0; i < last_; i++){
		K pair_key = ary_[i].first;

		//return key if it matches
		if(pair_key == key){
			return ary_[i]; 
		}
	}
	return Node<K,V>(); //return empty node if not found
}

//update mapset value
//param: 	K key, V value
//return:	bool
template<typename K, typename V>
bool MapSet<K,V>::update(K key, V value){

	auto item = Node<K,V>(key, value);

	//if value not in there
	if(get(key)== Node<K, V>()){
		return false;
	}
	remove(key);
	add(item);
	return true;
}

//see which mapset is larger 1 for this, -1 for param, 0 for same set
//param:	MapSet &ms
//return:	int comparision_result
template<typename K, typename V>
int MapSet<K,V>::compare(MapSet &ms){

	long smaller_size = 0;

	(size()<ms.size()) ? (smaller_size = size()):(smaller_size = ms.size());

	//determines if any values are not equal
	for(int i = 0; i < smaller_size; i++){ //through both up to smallest size
		if(ary_[i].first != ms.ary_[i].first){ //if elements differ
			if(ary_[i].first > ms.ary_[i].first){ //compare first strings of set that differ
				return 1; //calling is bigger
			}
			return -1; //param is bigger
		}
	}

	if(size()>ms.size()){ //calling is bigger
		return 1;
	}
	else if(size() == ms.size()){ //if they are the same set
		return 0;
	}

	return -1; //param is bigger
}

//get union of all mapset elements
//param:	MapSet &ms
//return:	MapSet result
template<typename K, typename V>
MapSet<K,V> MapSet<K,V>::mapset_union(MapSet<K,V> &ms){

	//basically tries to add all entries, duplicate keys ignored, calling list added first
	MapSet result;
	for(int i = 0; i < last_; i++){
		result.add(ary_[i]); //add elements from calling vector
	}
	for(int i = 0; i < ms.last_; i++){
		result.add(ms.ary_[i]); //add elements from param vector
	}
	return result;
}

//mapset intersection
//param:	MapSet &ms
//return:	MapSet result
template<typename K, typename V>
MapSet<K,V> MapSet<K,V>::mapset_intersection(MapSet<K,V> &ms){
	MapSet result;

	//compare all set values to each other
	for(int i = 0; i < last_; i++){ //this.mapset
		for(int j = 0; j < ms.last_; j++){ //ms.mapset
			K s = ary_[i].first; //key of node in this.ary_
			K param_s = ms.ary_[j].first; //key of node in ms.ary_
			if(s == param_s){ //pair in both
				result.add(ary_[i]);
			}
		}
	}
	return result;
}

#endif