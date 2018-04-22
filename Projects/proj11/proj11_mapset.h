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
using std::swap;

//
// Node structure
//
template<typename K, typename V>
struct Node {
    K first;
    V second;
    Node<K,V>* next_ = nullptr;

    Node() = default;
    Node(K,V);
    bool operator<(const Node&) const;
    bool operator==(const Node&) const;
    friend ostream& operator<<(ostream &out, const Node &n){
        out << n.first << ":" << n.second; //print node key and value out
        return out;
    }
};

//constructor for node given key and value
template<typename K, typename V>
Node<K,V>::Node(K key, V value){
    first = key;
    second = value;
    //Node<K, V> *next_ = nullptr;
}

//operator < overload for node 
template<typename K, typename V>
bool Node<K,V>::operator<(const Node &n) const{
    return (first < n.first);
}

//operator == overload for node
template<typename K, typename V>
bool Node<K,V>::operator==(const Node &n) const{
    return (first == n.first);
}

//
// MapSet class
//
template<typename K, typename V>
class MapSet{
private:
    Node<K,V>* head_ = nullptr;
    Node<K,V>* tail_ = nullptr;
    size_t sz_ = 0;
    Node<K,V> find_key(K);

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

        ostringstream oss;
        for(auto *ptr = ms.head_; ptr != nullptr; ptr = ptr->next_){ //print out mapset
            oss << *ptr << ", "; //comma between mapset items
        }
        string s = oss.str();
        s = s.substr(0,s.size()-2); //remove trailing comma
        out << s;

        return out;
    }
};

//initializer list constructor
template<typename K, typename V>
MapSet<K,V>::MapSet(initializer_list< Node<K,V> > il){

    head_ = nullptr;
    tail_ = nullptr;
    sz_ = 0;

    //add elements to linked list
    for(auto element: il){
        add(element);
    }
}

//mapset constructor (mapset as param)
template<typename K, typename V>
MapSet<K,V>::MapSet(const MapSet &ms){

    if(ms.head_ == nullptr){
        head_ = nullptr;
        tail_ = nullptr;
        sz_ = 0;
    }
    //initialize mapset param to current mapset
    else{
		//go through and transfer param values to new node
        head_ = new Node<K,V>(ms.head_->first,ms.head_->second);
        tail_ = head_;
        Node<K, V>* ms_ptr = ms.head_->next_;
        Node<K, V>* new_node;
        //do until end of linked list
        while(ms_ptr != nullptr){
            new_node = new Node<K,V>(ms_ptr->first, ms_ptr->second); //new k,v node in this mapset
            tail_ -> next_ = new_node; //add node onto end of linked list
            ms_ptr = ms_ptr->next_;
            tail_ = new_node;
        }
    }
}

//assingment operator overload for mapsets
template<typename K, typename V>
MapSet<K,V> MapSet<K,V>::operator=(MapSet ms){
    swap(head_, ms.head_);
    swap(tail_, ms.tail_);
    swap(sz_, ms.sz_);
    return *this;
}

// walk down the list, moving head_ but remember it in to_del
// delete each node in turn, the set head_ and tail_
template<typename K, typename V>
MapSet<K,V>::~MapSet(){

	//go through and delete all the nodes
    for(auto *to_del = head_; to_del !=nullptr; to_del = to_del->next_){
        delete to_del;
    }
    head_ = nullptr;
    tail_ = nullptr;
}

//get mapset size
template<typename K, typename V>
size_t MapSet<K,V>::size(){

    size_t count = 0;

    for(auto ptr = head_; ptr != nullptr; ptr = ptr->next_){ //count mapset items
        count ++;
    }
    return count;
}

//return node value based on key
template<typename K, typename V>
Node<K,V> MapSet<K,V>::find_key(K key){

    for(auto ptr = head_; ptr != nullptr; ptr = ptr->next_){ //look for node in mapset based on key
        if (key == ptr->first){
            return *ptr; //return node 
        }
    }
    return Node<K,V>(); //empty node if not found
}

//add entry to mapset
template<typename K, typename V>
bool MapSet<K,V>::add(Node<K,V> n){

	//new item to insert into linked list
    Node<K, V>* param_item = new Node<K, V>(n.first, n.second);

	//initialize linked list if empty
    if(sz_ == 0){
        head_ = param_item;
        tail_ = param_item;
        sz_++;
        return true;
    }

	//check if its already in the mapset, can't add if it is
	for(auto *ptr = head_; ptr!=nullptr; ptr = ptr->next_){
        if(ptr->first == param_item->first){
        	return false;
        }
	}

    //find insert point at lower bound
    Node<K, V>* insert_point = nullptr;
    for(auto *ptr = head_; ptr!=nullptr; ptr = ptr->next_){
        if(ptr->first < param_item->first){
            insert_point = ptr;
            continue;
        }
        else{
            break; //item found is larger than the this->first
        }
    }

    //insert value if there is already one item in the mapset
    if (sz_ != 0){
        //insert beginning
        if(*param_item < *head_){
            param_item->next_ = head_;
			head_ = param_item;
			sz_++;
			return true;
        }
            //insert end
        else if(*tail_ < *param_item){
            tail_->next_ = param_item;
			param_item->next_ = nullptr;
			tail_ = param_item;
			sz_++;
			return true;
        }
            //insert after certain item
        else{
            param_item->next_ = insert_point->next_; //link items before and after to new item
			insert_point->next_ = param_item; 
			if (insert_point == tail_){ //link to end if its at the end
				tail_ = &n;
			}
			sz_++;
			return true;
        }

    }
    else{
		//is nullptr because no items are in the mapset yet
        head_ = param_item;
        tail_ = param_item;
		sz_++;
		return true;
    }
	//base case, could not add item to mapset
    return false;
}

//remove entry from linked list
template<typename K, typename V>
bool MapSet<K,V>::remove(K key){

	//item not in mapset
	if(find_key(key) == Node<K, V>()){
		return false;
	}

	//node in mapset
	Node<K, V>* p = nullptr;
	Node<K, V>* q = nullptr;
	q = head_;
	p = head_->next_;

	//remove node at head
	if(q->first == key){
		head_ = p;
		delete(q);
		return true;
	}
	else{
		while(p->first != key){ //move nodes over past key
			p = p->next_;
			q = q->next_;
		}
	}
	if(p->next_ == nullptr){ //remove last node
		q->next_ = nullptr;
		delete(p);
		return true;
	}
	else{ //remove middle node
		q->next_ = p->next_;
		delete(p);
		return true;
	}
	return false;
}

//get node based on key
template<typename K, typename V>
Node<K,V> MapSet<K,V>::get(K key){

    for(auto *ptr = head_; ptr != nullptr; ptr = ptr->next_){
        if(ptr->first == key){
            return *ptr; //return found node
        }
    }
    return Node<K, V>(); //empty node if not found
}

//update value in list
template<typename K, typename V>
bool MapSet<K,V>::update(K key, V value){

    auto item = Node<K,V>(key, value); //new node from key and value to update

    //cannot update what is not there
    if(get(key)== Node<K, V>()){
        return false;
    }
    remove(key);
    add(item);
    return true;
}

//compare to mapsets
template<typename K, typename V>
int MapSet<K,V>::compare(MapSet &ms){

	long smaller_size = 0;
	Node<K, V> *p = head_;
	Node<K, V> *q = ms.head_;

	(size()<ms.size()) ? (smaller_size = size()):(smaller_size = ms.size());

	for(int i = 0; i < smaller_size; i++){ //through both up to smaller size one
		if(p->first != q->first){ //if they differ
			if(p->first > q->first){ //which one is larger
				return 1; //calling is bigger
			}
			return -1; //param is bigger
		}
		p = p->next_; //go to next items
		q = q->next_;
	}

	if(size()>ms.size()){ //calling is bigger
		return 1;
	}
	else if(size() == ms.size()){ //if they are the same set
		return 0;
	}

	return -1; //param is bigger
}

//union of mapset items
template<typename K, typename V>
MapSet<K,V> MapSet<K,V>::mapset_union(MapSet<K,V> &ms){
    MapSet result;

    //add elements from this
    for(auto ptr = head_; ptr != nullptr; ptr = ptr->next_){
        result.add(*ptr);
    }

    //add elements from param
    for(auto ptr = ms.head_; ptr != nullptr; ptr = ptr->next_){
        result.add(*ptr);
    }

    return result;
}

//intersection of mapset items
template<typename K, typename V>
MapSet<K,V> MapSet<K,V>::mapset_intersection(MapSet<K,V> &ms){
    MapSet result;

    for(auto itr = head_; itr != nullptr; itr = itr->next_){ //go through this items
        for(auto ptr = ms.head_; ptr != nullptr; ptr = ptr->next_){ //go through param items
			//extract keys from this and parameter
            K s = itr->first; 
            K param_s = ptr->first;
            if(s == param_s){ //keys match, both in mapsets
                result.add(*itr);
            }
        }
    }
    return result;
}

#endif