#ifndef SINGLELINK_H
#define SINGLELINK_H

#include<iostream>
using std::ostream; using std::cout; using std::endl;
#include <stdexcept>
using std::out_of_range;

template <typename T>
struct Node{
public:
    Node *next_;
    T data_;
    
Node() : data_( T() ), next_(nullptr) {};
Node(T d) : data_(d), next_(nullptr) {};
};

template <typename T>
class SingleLink{
private:
    Node<T> *head_;
    Node<T> *tail_;
  
public:
  SingleLink();         
  SingleLink(T dat);    
  void append_back(T);
  friend ostream& operator<<(ostream &out, SingleLink<T>& s){
      if (s.head_==nullptr){
          out << "empty sl";
          return out;
      }
      for (auto ptr=s.head_; ptr!=s.tail_; ptr=ptr->next_){
          out << ptr->data_ << ", ";
      }
      out << s.tail_->data_;
      return out;
  };
  bool del(T val);
  Node<T>& operator[](size_t index);
  
  // Rule of three stuff, if you get time. Look at 21.2
  ~SingleLink();
  SingleLink(const SingleLink &);
  SingleLink& operator=(SingleLink);
  
};

template <typename T>
SingleLink<T>::SingleLink(): head_(nullptr), tail_(nullptr){
}

template <typename T>
SingleLink<T>::SingleLink(T dat){
    // create a new node (allocate memory dynamically using new)
    auto n = new Node<T>(dat);
    head_ = tail_ = n;
}

template <typename T>
void SingleLink<T>::append_back(T dat){
    auto n = new Node<T>(dat);
    
    // empty list
    if (head_==nullptr){
        head_ = tail_ = n;
        return;
    }
    
    // not empty
    tail_->next_ = n;
    tail_ = n;
}

template <typename T>
bool SingleLink<T>::del(T to_del){
    // empty list
    if (head_==nullptr){
        return false;
    }
    
    // to_del is in head_
    if (head_->data_==to_del){
        auto temp = head_;
        head_ = head_->next_;
        delete temp;
        return true;
    }
    
    // to_del is in the middle or in tail_
    for (auto ptr=head_; ptr!=tail_; ptr=ptr->next_){
        // here we check the value of the node ahead of the current node, i.e. ptr->next_ (note that head_->data_ is already checked)
        if (ptr->next_->data_ == to_del){
            // save pointer to the node to delete later
            auto temp = ptr->next_;
            
            // update tail_ if tail_ is being deleted
            if (ptr->next_ == tail_){
                tail_ = ptr;
            }

            // ptr->next_ will be deleted, so ptr's next_ should point to ptr->next_->next_
            ptr->next_ = ptr->next_->next_;
            
            delete temp;
            return true;
        }
    }
    
    // to_del not found
    return false;
}

template <typename T>
Node<T>& SingleLink<T>::operator[](size_t index){
    // index cannot be negative since its type is size_t (unsigned integer). It will wrap around and take a huge value if a negative number is passed to this function
    size_t i=0;
    for (auto ptr=head_; ptr!=nullptr; ptr=ptr->next_){
        if (i==index){
            return *ptr;
        }
        i++;
    }
    
    // if index >= sz
    throw out_of_range("bad index");
}

template <typename T>
SingleLink<T>::~SingleLink(){
    for (auto ptr=head_; ptr!=nullptr; ){
        auto temp = ptr; // save ptr (pointer to current node) to delete later
        // update current node FIRST and then delete temp
        ptr = ptr->next_;
        delete temp;
        
        // note that if you delete temp first, ptr cannot be updated since both temp and ptr are pointing to the same object, i.e. current node, and deleting temp make ptr point to nullptr        
    }
}

template <typename T>
SingleLink<T>::SingleLink(const SingleLink &sl){
    // sl is empty
    if (sl.head_==nullptr){
        head_ = tail_ = nullptr;
        return;
    }
    
    auto n = new Node<T> (sl.head_->data_);
    head_ = tail_ = n;
    
    for (auto ptr=sl.head_->next_; ptr!=nullptr; ptr=ptr->next_){
        n = new Node<T> (ptr->data_);
        tail_->next_ = n;
        tail_ = n;
        /* The code above probably reminds you of append_back.
        In fact, we could use append_back() here too since in append_back function, we create new nodes by allocating memory. Note that if append_back() took a node as the argument (similar to example code), we could NOT use it in copy constructor.
        
        append_back(ptr->data_);
        */
    }
}

template <typename T>
SingleLink<T>& SingleLink<T>::operator=(SingleLink sl){
    swap(sl.head_, head_);
    swap(sl.tail_, tail_);
    return (*this);
}