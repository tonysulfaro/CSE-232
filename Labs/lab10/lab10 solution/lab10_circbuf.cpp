#include<iostream>
using std::ostream; using std::endl;
#include<string>
using std::string;
#include<stdexcept>
using std::runtime_error;
#include<algorithm>
using std::copy;
#include<sstream>
using std::ostringstream;
#include<iterator>
using std::back_inserter;
#include<stdexcept>
using std::range_error;

#include "lab10_circbuf.h"

// Constructor with initial size
CircBuf::CircBuf(size_t sz){
  sz_ = sz;
  cnt_= 0;
  buf_ = vector<long>(sz);
  head_ = 0;
  tail_ = 0;
}

// Constructor with initial values
CircBuf::CircBuf(initializer_list<long> il, size_t s){
  if (s < il.size() )
    throw range_error("size smaller than init list");
  buf_ = vector<long>(10,0);
  copy(il.begin(), il.end(), buf_.begin() );
  sz_ = s;
  cnt_ = il.size();
  head_= 0;
  tail_= cnt_;
}

// Check if CircBuf is full
bool CircBuf::full() const{
  return cnt_ == sz_;
}

// Check if CircBuf is empty
bool CircBuf::empty() const{
  return cnt_ == 0;
}

// Add element to CircBuf
void CircBuf::add(long element){
  if (full() )
    throw runtime_error("Error: CircBuf full");
  tail_ = (head_ + cnt_) % sz_; // where to add
  buf_[tail_] = element;
  tail_++; // next place to add
  cnt_++; // one more active element
}

// Pseudo remove element from CircBuf
// Item isn't really removed
void CircBuf::remove(){
  if (empty() )
    throw runtime_error("Error: CircBuf empty");
  else{
    int temp = head_ + 1;
    head_ = (temp >= sz_) ? 0 : temp; // loop around if past the end
    cnt_--; // one less active item
  }
}

// Read head element
long CircBuf::front() const{
  if (empty() )
    throw runtime_error("Error: CircBuf empty");
  else{
    long result = buf_[head_];
    return result;
  }
}

// Read end element
long CircBuf::back() const{
  if (empty() )
    throw runtime_error("Error: CircBuf empty");
  else{
    int temp = tail_ - 1;
    temp = (temp < 0) ? sz_ - 1 : temp;
    long result = buf_[temp];
    return result;
  }
}

ostream& operator<<(ostream& out, const CircBuf &cb){
  if (cb.empty() )
    out << "CircBuf empty";
  else{
    ostringstream oss;
    oss << "Front:"<<cb.buf_[cb.head_];
    int temp = cb.tail_ - 1;
    temp = (temp < 0) ? cb.sz_ - 1 : temp;
    oss << ", Back:" <<cb.buf_[temp]
	<<", Cnt:"<<cb.cnt_
	<<", Sz:" << cb.sz_ <<endl;
    for(int i=0;i<cb.sz_;i++)
      oss << cb.buf_[i]<<", ";
    string s = oss.str();
    s = s.substr(0,s.size()-2);
    out << s;
  }
  return out;
}

/*
CircBuf operator+(CircBuf &buf, long element){
    CircBuf temp(buf);
    if (temp.full())
      throw runtime_error("adding to full buffer");
    temp.tail_ = (temp.head_ + temp.cnt_) % temp.sz_;
    temp.buf_[temp.tail_] = element;
    temp.tail_++;
    temp.cnt_++;
    return temp;
}

CircBuf operator+(long element, CircBuf &buf){
  return operator+(buf, element);
}

CircBuf operator+(CircBuf &buf1, CircBuf &buf2){
    CircBuf temp(buf1.sz_ + buf2.sz_);
    copy(buf1.buf_.begin(), buf1.buf_.end(), temp.buf_.begin());
    // mark the end of the last copy. start copy there.
    auto itr = temp.buf_.begin() + buf1.sz_;
    copy(buf2.buf_.begin(), buf2.buf_.end(), itr);
    return temp;
}
*/