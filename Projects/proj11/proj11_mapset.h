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

//debugging
using std::cout; using std::endl;

//
// Node
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
        out << n.first << ":" << n.second;
        return out;
    }
};

template<typename K, typename V>
Node<K,V>::Node(K key, V value){
    first = key;
    second = value;
    Node<K, V> *next_ = nullptr;
}

template<typename K, typename V>
bool Node<K,V>::operator<(const Node &n) const{
    return (first < n.first);
}

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
        for(auto *ptr = ms.head_; ptr != nullptr; ptr = ptr->next_){
            oss << *ptr << ", ";
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
        head_ = new Node<K,V>(ms.head_->first,ms.head_->second);
        tail_ = head_;
        Node<K, V>* ms_ptr = ms.head_->next_;
        Node<K, V>* new_node;
        //do until end of linked list
        while(ms_ptr != nullptr){
            new_node = new Node<K,V>(ms_ptr->first, ms_ptr->second); //new k,v in node
            tail_ -> next_ = new_node; //add node onto end of linked list
            ms_ptr = ms_ptr->next_;
            tail_ = new_node;
        }
    }
}

//assingment operator
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
    Node <K,V>* to_del = head_;

    while (to_del !=nullptr){
        head_ = head_->next_;
        delete to_del;
        to_del = head_;
    }
    head_ = nullptr;
    tail_ = nullptr;
}

//get mapset size
template<typename K, typename V>
size_t MapSet<K,V>::size(){

    size_t count = 0;

    for(auto ptr = head_; ptr != nullptr; ptr = ptr->next_){
        count ++;
    }
    return count;
}

//return node value based on key
template<typename K, typename V>
Node<K,V> MapSet<K,V>::find_key(K key){

    for(auto ptr = head_; ptr != nullptr; ptr = ptr->next_){
        if (key == ptr->first){
            return *ptr;
        }
    }
    return Node<K,V>();
}

//add entry to mapset
template<typename K, typename V>
bool MapSet<K,V>::add(Node<K,V> n){

	//new item to insert into linked list
    Node<K, V>* item = new Node<K, V>(n.first, n.second);

	//initialize linked list if empty
    if(sz_ == 0){
        head_ = item;
        tail_ = item;
        sz_++;
        return true;
    }


    //insert after items in list 
	/*
    tail_->next_ = item;
    item->next_ = nullptr;
    tail_ = item;
    sz_++;
    return true; */

    //find insert point
    Node<K, V>* insert_point = nullptr;
    for(auto *ptr = head_; ptr!=nullptr; ptr = ptr->next_){
        //cout << "loop" << endl;
        K key = ptr->first;
        K param_key = item->first;
        if(key == param_key){
        	return false;
        }
        if(key < param_key){
            insert_point = ptr;
            continue;
        }
        else{
            //insert_point = ptr;
            break;
        }
    }
    //cout << "INSERT POINT" << insert_point << endl;

    //cout << "AFTER FIND INSERT POINT" << endl;

    //insert value
    if (insert_point != nullptr){
        //cout << "Not Null Ptr" << endl;
        //insert beginning
        if(item < head_){
            item->next_ = head_;
			head_ = item;
			sz_++;
			return true;
        }
            //insert end
        else if(item > tail_){
            tail_->next_ = item;
			item->next_ = nullptr;
			tail_ = item;
			sz_++;
			return true;
        }
            //insert after
        else{
            item->next_ = insert_point->next_;
			insert_point->next_ = item;
			if (insert_point == tail_){
				tail_ = &n;
			}
			sz_++;
			return true;
        }

    }
    else{
        //cout << "Is null ptr" << endl;
        head_ = item;
        tail_ = item;
		sz_++;
		return true;
    }
    //cout << sz_ << endl;

    return false;
}

//remove entry from linked list
template<typename K, typename V>
bool MapSet<K,V>::remove(K key){

}

//get node based on key
template<typename K, typename V>
Node<K,V> MapSet<K,V>::get(K key){

    for(auto *ptr = head_; ptr != nullptr; ptr = ptr->next_){
        if(ptr->first == key){
            return *ptr;
        }
    }
    return Node<K, V>();
}

//update value in list
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

//compare to mapsets
template<typename K, typename V>
int MapSet<K,V>::compare(MapSet &ms){

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

    for(auto itr = head_; itr != nullptr; itr = itr->next_){
        for(auto ptr = ms.head_; ptr != nullptr; ptr = ptr->next_){
            K s = itr->first;
            K param_s = ptr->first;
            if(s == param_s){
                result.add(*itr);
            }
        }
    }

    return result;
}

#endif