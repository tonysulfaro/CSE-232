#ifndef DOUBLELINK_H
#define DOUBLELINK_H

#include<iostream>
using std::ostream; using std::cout; using std::endl; using std::to_string;
#include<iomanip>
using std::hex;
#include<sstream>
using std::ostringstream;

template<typename T>
class DoubleLink;

template <typename T>
class Node{
private:
    Node *next_ = nullptr;
    Node *prev_ = nullptr;
    T data_ = T();
    ostream& print_node(ostream&);    
    string tail_4(Node<T> *ptr);
  
public:
    Node()=default;
    Node(T d) : next_(nullptr), prev_(nullptr), data_(d) {};

    friend ostream& operator<<(ostream& out, Node& n){
	out << n.data_;
	return out;
    }
    friend class DoubleLink<T>;
};

template<typename T>
string Node<T>::tail_4(Node<T> *ptr){
    string result;
    if (ptr == nullptr)
	result="0";
    else {
	ostringstream oss;
	oss << hex;
	oss << ptr;
	result = oss.str();
	result = result.substr(10);
    }
    return result;
}

template<typename T>
ostream& Node<T>::print_node(ostream& out){
    out << "Node:"<<tail_4(this)<<":"<<data_<<":"<<tail_4(prev_)<<":"<<tail_4(next_)<<", ";
    return out;
}

template<typename T>
class DoubleLink{
private:
    Node<T> *head_;
    Node<T> *tail_;
    ostream& print_list(ostream&);
  
public:
    DoubleLink() : head_(nullptr), tail_(nullptr) {};
    DoubleLink(T d);
    DoubleLink(const DoubleLink&);
    DoubleLink& operator=(DoubleLink);
    ~DoubleLink();    
    void append_front(Node<T> &n);
    void append_front(T dat);
    void append_back(Node<T> &n);
    void append_back(T dat);
    Node<T>* find(T dat);
    void insert_after(Node<T> &n, Node<T> *ptr);
    void insert_after(T dat, Node<T> *ptr);   

    friend ostream& operator<<(ostream& out, DoubleLink<T>& dl){
	dl.print_list(out);
	return out;
    };
};

template<typename T>
DoubleLink<T>::DoubleLink(T d){
    Node<T>* ptr = new Node<T>(d);
    head_ = ptr;
    tail_ = ptr;
};

/* 
bit of work. we need to remember a pointer that walks
down sl, and tail_ walks down the new list. 
make a new node (copy the current sl node), update
 */
template<typename T>
DoubleLink<T>::DoubleLink(const DoubleLink& dl){
    if (dl.head_ == nullptr){
	head_ = nullptr;
	tail_ = nullptr;
    }
    else{
	head_ = new Node<T>(dl.head_->data_);
	tail_ = head_;
	Node<T>* dl_ptr = dl.head_->next_;
	Node<T>* new_node;
	while (dl_ptr != nullptr){
	    new_node = new Node<T>(dl_ptr->data_);
	    tail_->next_ = new_node;
	    new_node->prev_ = tail_;
	    dl_ptr = dl_ptr->next_;
	    tail_ = new_node;
	}
    }
}

template<typename T>
DoubleLink<T>& DoubleLink<T>::operator=(DoubleLink dl){
    swap(head_, dl.head_);
    swap(tail_, dl.tail_);
    return *this;
}
	

// walk down the list, moving head_ but remember it in to_del
// delete each node in turn, the set head_ and tail_
template<typename T>
DoubleLink<T>::~DoubleLink(){
    Node<T>* to_del = head_;
    while (to_del != nullptr){
	head_ = head_->next_;
	delete to_del;
	to_del = head_;
    }
    head_ = nullptr;
    tail_ = nullptr;
}

// append node n to the end of the list
// fast because of the tail_ pointer
template<typename T>
void DoubleLink<T>::append_back(Node<T> &n){
    if (tail_ != nullptr){
	tail_->next_ = &n;
	n.prev_ = tail_;
	n.next_ = nullptr;
	tail_ = &n;
    
    }
    else {
	// cout << "first node";
	// n.print_node(cout)<<endl;
	head_=&n;
	tail_=&n;
    }
}

template<typename T>
void DoubleLink<T>::append_back(T dat){
    Node<T>* n = new Node<T>(dat);
    append_back(*n);
}

// append node n to the front of the list
// fast because of the head_ pointer
template<typename T>
void DoubleLink<T>::append_front(Node<T> &n){
    if (head_ != nullptr){
	n.next_ = head_;
	n.prev_=nullptr;
	head_->prev_ = &n;
	head_ = &n;
    }
    else {
	head_=&n;
	tail_=&n;
    }
}

template<typename T>
void DoubleLink<T>::append_front(T dat){
    Node<T>* n = new Node<T>(dat);
    append_front(*n);
}

template<typename T>
Node<T> * DoubleLink<T>::find(T dat){
  Node<T> *result = nullptr;
  for(Node<T> *n = head_; n != nullptr; n = n->next_){
    if (n->data_ == dat){
      result = n;
      break;
    } // of if
  } // of for
  return result;
}

// insert new node n after *ptr
template<typename T>
void DoubleLink<T>::insert_after(Node<T> &n, Node<T> *ptr){
    if (ptr != nullptr){
	n.next_ = ptr->next_;
	n.prev_ = ptr;
	(ptr->next_)->prev_ = &n;
	ptr->next_ = &n;
	if (ptr == tail_)
	    tail_ = &n;
    }
};

template<typename T>
void DoubleLink<T>::insert_after(T dat, Node<T> *ptr){
  Node<T> *n = new Node<T>(dat);
  insert_after(*n, ptr);
}

template<typename T>
ostream& DoubleLink<T>::print_list(ostream &out){
    Node<T> *ptr;
    for(ptr = head_; ptr != nullptr; ptr = ptr->next_)
	out << *ptr << ",";
    return out;
};

#endif
  
