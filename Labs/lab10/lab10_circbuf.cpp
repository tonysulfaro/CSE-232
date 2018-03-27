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
CircBuf::CircBuf(size_t s){
	sz_ = s;
	cnt_ = 0;
	vector<long> buf_(s,0);
	head_ = buf_.front();
	tail_ = buf_.back();
}

//args constructor
CircBuf::CircBuf(initializer_list<long> initialize_list, size_t s){

	//error handling
	if(s < 1){
		throw std::runtime_error("Invalid Size");
	}

	sz_ = s;
	cnt_ = 0;
	buf_= initialize_list;
	head_ = buf_.front();
	tail_ = buf_.back();
}

//output ovveride
ostream& operator<<(ostream& out, const CircBuf &cb){
	vector<long> buffer = cb.buf_;
	for(auto element: buffer){
		cout << element;
	}
  return out;
} 

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