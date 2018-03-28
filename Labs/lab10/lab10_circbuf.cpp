#include<iostream>
using std::ostream; using std::cout; using std::endl;
#include<string>
using std::string; using std::to_string;
#include<sstream>
using std::ostringstream; using std::istringstream;
#include<vector>
using std::vector;
#include<initializer_list>
using std::initializer_list;
#include <stdexcept>
using std::runtime_error;

#include "lab10_circbuf.h"

//default constructor
CircBuf::CircBuf(size_t s){
	sz_ = s;
	cnt_ = 0;
	buf_ = vector<long>(s,0);
	buf_.reserve(s);
	head_ = 0;
	tail_ = 0;
}

//args constructor
CircBuf::CircBuf(initializer_list<long> init_list, size_t s){

	//error handling
	if(s < init_list.size()){
		throw runtime_error("Invalid Size");
	}

	sz_ = s;
	cnt_ = init_list.size();
	buf_ = init_list;

	while(buf_.size() < s){
		buf_.push_back(0);
	}

	//get head and tail
	head_ = 0;
	tail_ = 0;
}

//output ovveride
ostream& operator<<(ostream& out, const CircBuf &cb){
	if(cb.empty()){
		out << "CircBuf empty";
		return out;
	}
	vector<long> buffer = cb.buf_;

	//print stats
	out << "Front:" << cb.front() << ", "<< "Back:" << cb.back() << ", ";
	out << "Cnt:" << cb.cnt_ << ", " << "Sz:" << cb.sz_ << '\n';

	//print elements
	for(auto element: buffer){
		out << element << ", ";
	}
  return out;
} 

//getter methods//
//front
long CircBuf::front() const{ 
	if(buf_.empty()){
		throw runtime_error("runtime error");
	}
	return buf_[head_];
}
//back
long CircBuf::back() const{ 
	if(buf_.empty()){
		throw runtime_error("runtime error");
	}
	return buf_[tail_-1];
}
//full
bool CircBuf::full() const{ 
	return count(buf_.begin(),buf_.end(),0) == 0;
}
//empty
bool CircBuf::empty() const{ 
	return (head_== tail_);
}

//setter methods//
//add
void CircBuf::add(long num){ 
	if(full()){
		throw runtime_error("runtime error");
	}
	buf_[tail_]= num;
	cnt_++;
	tail_ = (head_+cnt_)%sz_;
	
} 
//remove
void CircBuf::remove(){
	if(empty()){
		throw runtime_error("runtime error");
	}
	else{
		head_++;
	}
}