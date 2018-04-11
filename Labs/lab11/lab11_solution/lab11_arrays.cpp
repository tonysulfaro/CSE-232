#include<iostream>
using std::cout; using std::endl; using std::cin; using std::ostream;
#include<fstream>
using std::ifstream;
#include<string>
using std::string;
#include<algorithm>
using std::copy; using std::copy_if; using std::count_if;
#include<iterator>
using std::ostream_iterator; using std::begin; using std::end;
#include<utility>
using std::pair; using std::make_pair;
#include<sstream>
using std::ostringstream;
#include<stdexcept>
using std::runtime_error;
#include "lab11_arrays.h"

bool is_even(long l){
  return (l%2 == 0);
}

void print_array(long ary[], size_t sz, ostream& out){
  ostringstream oss;
  copy(ary, (ary + sz), ostream_iterator<long>(oss, ", "));
  string s = oss.str();
  s = s.substr(0, s.size() - 2);
  out << s;
}

size_t fill_from_file(long* (& ary), string f_name){
  size_t sz;
  long num;
  size_t i = 0;
  ifstream ifs(f_name);
  if (! ifs.is_open() )
    throw runtime_error("file does not exist: "+f_name);
  ifs >> sz;
  ary = new long[sz];
  while (ifs >> num && i<sz){
    ary[i] = num;
    i++;
  }
  return sz;
}

size_t concatenate(long* (& ary1), size_t sz1, long ary2[], size_t sz2){
  size_t new_sz = sz1 + sz2;
  long* ary_new = new long[new_sz];
  long* temp;
  copy(ary1, (ary1+sz1), ary_new);
  copy(ary2, (ary2+sz2), (ary_new + sz1));
  temp = ary1;
  ary1 = ary_new;
  delete [] temp;
  return new_sz;
}
pair<long*, size_t> copy_evens(long ary[], size_t sz){
  size_t cnt;
  long* new_ary;
  cnt = count_if(ary, (ary + sz), is_even);
  new_ary = new long [cnt];
  copy_if(ary, ary+sz, new_ary, is_even);
  return make_pair(new_ary, cnt);
}