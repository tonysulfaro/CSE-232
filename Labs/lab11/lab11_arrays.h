#ifndef LAB11_ARRAYS
#define LAB11_ARRAYS
#include<string>
using std::string;
#include<utility>
using std::pair;
#include<iostream>
using std::ostream;


bool is_even(long l);

void print_array(long ary[], size_t sz, ostream& out);

size_t fill_from_file(long* (& ary), string f_name);

size_t concatenate(long* (& ary1), size_t sz1, long ary2[], size_t sz2);

pair<long*, size_t> copy_evens(long ary[], size_t sz);

#endif
