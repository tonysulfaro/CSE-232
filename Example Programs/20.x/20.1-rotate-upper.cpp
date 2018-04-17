#include<iostream>
using std::cout; using std::endl; using std::ostream;
#include<algorithm>
using std::upper_bound; using std::rotate; using std::sort;
#include<sstream>
using std::ostringstream;
#include<iterator>
using std::ostream_iterator; using std::begin;
using std::end; using std::distance;

template<typename T, size_t S>
ostream& dump(ostream& out, T (&ary)[S]){
  copy(begin(ary), end(ary), ostream_iterator<T>(out, ", "));
  return out;
}

int main (){
  long ary[]{3,2,9,5,4,1,7,0};
  dump(cout, ary) << endl;

  rotate(begin(ary), ary+2, end(ary));
  dump(cout, ary) << endl;

  long ary2[]{9,5,4,1,7,0,3,2};
  rotate(ary2+2, ary2+4, ary2+6 );
  dump(cout, ary2) << endl;

  long ary3[]{1,2,3,4,5,1,2,3,4,5};
  sort(begin(ary3),end(ary3));
  dump(cout,ary3) << endl;
  long *result = upper_bound(begin(ary3), end(ary3), ary3[2]);
  cout << *result << " just greater than "<<ary3[2] << endl;
  cout << "Index:"<<distance(begin(ary3), result)<<endl;
}
