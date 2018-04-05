#include<iostream>
using std::cout; using std::cin; using std::endl; using std::ostream;
#include<algorithm>
using std::copy; using std::swap;
#include<iterator>
using std::ostream_iterator;

template<typename T>
ostream& print_ary(T* ary, size_t sz, ostream& out){
  copy(ary, ary+sz, ostream_iterator<T>(out, ", ") );
  out << "Sz:"<<sz;
  return out;
}

template<typename T>
void insert(T* (&ary), size_t &sz, size_t indx, T val){
  if (indx >= sz){
    sz = indx+1;
    cout << "growing to size:"<<indx+1<<endl;
    T* new_ary = new T[sz]{};
    copy(ary, ary+sz, new_ary);
    swap(ary,new_ary); // new_ary now points to old, ary to new
    delete [] new_ary; // delete the old
  }
  ary[indx] = val;
}


int main(){
  size_t sz = 4;

  long *ary_ptr = new long[sz]{1,2,3,4};
  print_ary(ary_ptr, sz, cout) << endl;

  insert(ary_ptr, sz, 10 , 15l);
  print_ary(ary_ptr, sz, cout) << endl;
  cout << "Size:"<<sz<<endl;
  delete [] ary_ptr;
}
