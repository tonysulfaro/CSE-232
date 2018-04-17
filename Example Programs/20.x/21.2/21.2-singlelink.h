#ifndef SINGLELINK_H
#define SINGLELINK_H

#include<iostream>
using std::ostream; using std::cout; using std::endl;
#include<utility>
using std::swap;
#include<sstream>
using std::ostringstream;
#include<string>
using std::string;

// forward declaration so we can make Node a friend of SingleLink
template<typename T>
class SingleLink;

//node class
template <typename T>
class Node{
private:
    Node *next_ = nullptr;
    T data_ = T();
  
public:
    Node()=default;
    Node(T d) : next_(nullptr), data_(d){};
    friend ostream& operator<<(ostream& out, Node& n){
	out << n.data_;
	return out;
    }
    friend class SingleLink<T>;
};


template<typename T>
class SingleLink{
private:
    Node<T> *head_ = nullptr;
    Node<T> *tail_ = nullptr;
    void print_list(ostream& out);  
public:
    SingleLink()=default;
    SingleLink(T d);
    SingleLink(const SingleLink&);
    SingleLink& operator=(SingleLink);
    ~SingleLink();
    void append_front(Node<T> &n);
    void append_front(T dat);
    void append_back(Node<T> &n);
    void append_back(T dat);
    Node<T>* find(T dat);
    void insert_after(Node<T> &n, Node<T> *ptr);
    void insert_after(T dat, Node<T> *ptr);    

    friend ostream& operator<<(ostream& out, SingleLink<T>& sl){
	sl.print_list(out);
	return out;
    };
};

template<typename T>
SingleLink<T>::SingleLink(T d){
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
SingleLink<T>::SingleLink(const SingleLink& sl){
    if (sl.head_ == nullptr){
	head_ = nullptr;
	tail_ = nullptr;
    }
    else{
	head_ = new Node<T>(sl.head_->data_);
	tail_ = head_;
	Node<T>* sl_ptr = sl.head_->next_;
	Node<T>* new_node;
	while (sl_ptr != nullptr){
	    new_node = new Node<T>(sl_ptr->data_);
	    tail_->next_ = new_node;
	    sl_ptr = sl_ptr->next_;
	    tail_ = new_node;
	}
    }
}

template<typename T>
SingleLink<T>& SingleLink<T>::operator=(SingleLink sl){
    // x = y
    // x.operator=(y);
    swap(head_, sl.head_);
    swap(tail_, sl.tail_);
    return *this;
}
	

// walk down the list, moving head_ but remember it in to_del
// delete each node in turn, the set head_ and tail_
template<typename T>
SingleLink<T>::~SingleLink(){
    Node<T>* to_del = head_;
    while (to_del != nullptr){
	head_ = head_->next_;
	delete to_del;
	to_del = head_;
    }
    head_ = nullptr;
    tail_ = nullptr;
}

// append node n to the front of the list
// fast because of the head_ pointer
template<typename T>
void SingleLink<T>::append_front(Node<T> &n){
    if (head_ != nullptr){
	n.next_ = head_;
	head_ = &n;
    }
    else {
	head_=&n;
	tail_=&n;
    }
}

template<typename T>
void SingleLink<T>::append_front(T dat){
    Node<T>* n = new Node<T>(dat);
    append_front(*n);
}

// append node n to the end of the list
// fast because of the tail_ pointer
template<typename T>
void SingleLink<T>::append_back(Node<T> &n){
    if (tail_ != nullptr){
	tail_->next_ = &n;
	tail_ = &n;
    }
    else {
	head_=&n;
	tail_=&n;
    }
}

template<typename T>
void SingleLink<T>::append_back(T dat){
    Node<T>* n = new Node<T>(dat);
    append_back(*n);
}

template<typename T>
Node<T> * SingleLink<T>::find(T dat){
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
void SingleLink<T>::insert_after(Node<T> &n, Node<T> *ptr){
    if (ptr != nullptr){
	n.next_ = ptr->next_;
	ptr->next_ = &n;
	if (ptr == tail_)
	    tail_ = &n;
    }
}

template<typename T>
void SingleLink<T>::insert_after(T dat, Node<T> *ptr){
  Node<T> *n = new Node<T>(dat);
  insert_after(*n, ptr);
}

template<typename T>
void SingleLink<T>::print_list(ostream &out){
    ostringstream oss;
    Node<T> *ptr;
    for(ptr = head_; ptr != nullptr; ptr = ptr->next_)
	oss << *ptr << ",";
    string s = oss.str();
    out << s.substr(0,s.size()-1);
};


#endif
  
