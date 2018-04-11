#include <iostream>
using std::cout;
using std::endl;
using std::ostream;
#include <sstream>
using std::ostringstream;
using std::initializer_list;
using std::copy;

namespace student{

	template<typename T>
	class vector{

		private:

		T  *data_ = nullptr;
		size_t capacity_ = 0;
		size_t size_ = 0;

		public:

		//vector()= default;
		//vector(initializer_list<T>);

		//constructor size
		vector(size_t capacity = 10);
		vector(initializer_list<T> il);

		//functions
		size_t capacity();
		size_t size();

		//part 2 functions
		void push_back(T val);
		T& operator[](size_t val);
		
	};

	//constructor size
	template<typename T>
	vector<T>::vector(size_t capacity){
			capacity_ = capacity;
			size_ = 0;
			T * data_ = nullptr;
	}

	//init list constructor
	template<typename T>
	vector<T>::vector(initializer_list<T> il){
			capacity_ = il.size();
			size_ = il.size();
			copy(il, il+size_, data_);
	}

	//get capacity
	template<typename T>
	size_t vector<T>::capacity(){
		return capacity_;
	}

	//get size_
	template<typename T>
	size_t vector<T>::size(){
		return size_;
	}

	//PART 2/

	//Takes a single parameter of template type and adds it to the end of the vector
	template<typename T>
	void vector<T>::push_back(T val){
		if(capacity_ == size_){
			T *new_ary;

			if (capacity_ == 0){
				new_ary = new T[1]{};
				capacity_ = 1;
				data_ = new_ary;
			}
			else{
				new_ary = new T[capacity_*2]{};
				copy(data_, data_+size_, new_ary);
				capacity_ *=2;
				//swap the pointers
				std::swap(new_ary,data_);
				delete [] new_ary;
			}
		}
		data_[++size_] = val;
	}

	//takes single argument which is the index in the original call and returns a reference to the element.
	template<typename T> 
	T& operator[](size_t val){
		
	}


	//part 3 
	/*

	template<typename T>
	T* vector<T>::front(){
		return data_.front();
	}

	template<typename T>
	T* back(){
		return data_.back();
	} */
};
