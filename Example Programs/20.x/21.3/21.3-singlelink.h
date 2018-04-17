#ifndef SINGLELINK_H
#define SINGLELINK_H

#include<iostream>
using std::ostream; using std::cout; using std::endl;
#include<algorithm>
using std::copy; using std::swap;
#include<iterator>
using std::ostream_iterator;


template<typename T>
class SingleLink{

private:
    // private Node struc
    struct Node{
    public:
	Node *next_;
	T data_;
	
	Node() : next_(nullptr) {};
        Node(T d) : next_(nullptr), data_(d) {};
    };

    // SL data elements
    Node* head_;
    Node* tail_;

public:
    SingleLink() : head_(nullptr), tail_(nullptr) {};
    SingleLink(T dat);
    SingleLink(const SingleLink&);
    SingleLink& operator=(SingleLink);
    ~SingleLink();
    void append_front(T);
    void append_back(T);
    bool find(T, Node*&);  
    void insert_after(T dat, T to_find);
    friend ostream& operator<<(ostream& out, SingleLink<T>& l){
	for(auto ptr = l.head_; ptr != nullptr; ptr = ptr->next_)
	    cout << ptr->data_ << ",";
	return out;
    }
};

template<typename T>
SingleLink<T>::SingleLink(T dat){
  head_ = new Node(dat);
  tail_ = head_;
}

/* 
bit of work. we need to remember a pointer that walks
down sl, and tail_ walks down the new list. 
make a new node (copy the current sl node), update
 */
template<typename T>
SingleLink<T>::SingleLink(const SingleLink& sl){
    if (sl.head_ == nullptr){
	head_ = nullptr;
	tail_ = nullptr;
    }
    else{
	head_ = new Node(sl.head_->data_);
	tail_ = head_;
	Node* sl_ptr = sl.head_->next_;
	Node* new_node;
	while (sl_ptr != nullptr){
	    new_node = new Node(sl_ptr->data_);
	    tail_->next_ = new_node;
	    sl_ptr = sl_ptr->next_;
	    tail_ = new_node;
	}
    }
}

template<typename T>
SingleLink<T>& SingleLink<T>::operator=(SingleLink sl){
    swap(head_, sl.head_);
    swap(tail_, sl.tail_);
    return *this;
}

// walk down the list, moving head_ but remember it in to_del
// delete each node in turn, the set head_ and tail_
template<typename T>
SingleLink<T>::~SingleLink(){
    Node* to_del = head_;
    while (to_del !=nullptr){
	head_ = head_->next_;
	delete to_del;
	to_del = head_;
    }
    head_ = nullptr;
    tail_ = nullptr;
}
    
// make a node n, init with dat
// append node n to the end of the list
// fast because of the tail_ pointer
template<typename T>
void SingleLink<T>::append_back(T dat){
    Node* n = new Node(dat);
    if (tail_ != nullptr){
	tail_->next_ = n;
	tail_ = n;
    }
    else {
	head_=n;
	tail_=n;
    }
}

// append node n to the front of the list
// fast because of the head_ pointer
template<typename T>
void SingleLink<T>::append_front(T dat){
    Node* n = new Node(dat);
    if (head_ != nullptr){
	n->next_ = head_;
	head_ = n;
    }
    else {
	head_=n;
	tail_=n;
    }
}

// you'd like to return the node, but you can't because it's private
// and returning it would require it to be public
// so we pass in a node reference and set the value there
template<typename T>
bool SingleLink<T>::find(T dat, Node*& n){
    for(Node* ptr = head_; ptr != nullptr; ptr = ptr->next_)
	if (dat == ptr->data_){
	    n = ptr;
	    return true;
	}
    return false;
}


// insert new node n after node with the value to_find
// or if not found, append at the end
template<typename T>
void SingleLink<T>::insert_after(T dat, T to_find){
    Node* found_node;
    bool found_it = find(to_find, found_node);
    if (found_it == false || found_node == tail_)
	append_back(dat);
    else{
	Node* n = new Node(dat);
	n->next_ = found_node->next_;
	found_node->next_ = n;
    }
}

#endif
  
