#include<iostream>
using std::ostream; using std::cout; using std::endl;
#include<string>
using std::string;
#include<sstream>
using std::ostringstream; using std::istringstream;
#include<vector>
using std::vector;
#include<initializer_list>
using std::initializer_list;

#include "lab10_circbuf.h"

//default constructor
CircBuf::CircBuf(long size){
	sz_ = size;
}

//args constructor
CircBuf(initializer_list<long> initialize_list, size_t size){
	buf_= initializer_list;
	
}

//output ovveride
/*
ostream& operator<<(ostream&, const CircBuf &cb){
	cout << "op<< function"<<endl;
  	out << "Hours:"<<cb.hours_<<", Minutes:"
    <<c.minutes_<<", Period:"<<cb.period_;
  return out;
} */

//getter methods//
//front
long CircBuf::front() const{ return buf_.front();}
//back
long CircBuf::back() const{ return buf_.back();}
//full
bool CircBuf::full() const{ return buf_.size() == sz_;}
//empty
bool CircBuf::empty() const{ return buf_.size() == 0;}

//setter methods//
//add
void CircBuf::add(long num){ buf_.push_back(num);} 
//remove
void CircBuf::remove(){buf_.erase(buf_.begin());}