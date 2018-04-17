#include<iostream>
using std::cout; using std::endl; using std::ostream;
#include<string>
using std::string;
#include<list>
using std::list;
#include<iterator>
using std::ostream_iterator;

ostream& print_lst(ostream& out, list<string> &l){
  if (l.empty())
    out << "Empty";
  else
    copy(l.begin(), l.end(), ostream_iterator<string>(out, ", "));  //bi-directional iterators
  return out;
}
       
int main () {
  list<string> lst;
  lst.push_back("seen");         // string has a copy constructor, pushes a copy
  lst.push_back("rain");
  lst.push_front("I've");
  print_lst(cout, lst) << endl;
  
  list<string> copy_lst(lst);    // copy constructor
  copy_lst.sort();              // string has a operator< , sorts using that
  print_lst(cout, copy_lst) << endl;

  list<string> merge_lst(lst);
  merge_lst.sort();
  merge_lst.merge(copy_lst);     // merges two sorted lists as a move. copy_lst is now empty
  print_lst(cout, merge_lst) << endl;
  print_lst(cout, copy_lst) << endl;  // now empty

  merge_lst.remove("seen");    // string has operator== , removes every example of arg based on that
  print_lst(cout, merge_lst) << endl;

  merge_lst.unique();         // on sorted list, removes consecutive equal elements. Requires op==
  print_lst(cout, merge_lst) << endl;

  list<string> a_lst{"I've","seen", "fire", "and"}; // list inititialization
  print_lst(cout, a_lst) << endl;
  auto itr = merge_lst.begin();
  merge_lst.splice(itr, a_lst); // move all of a_lst to beginning of merge_lst
  print_lst(cout, merge_lst) << endl;
  print_lst(cout, a_lst) << endl; // now empty

  itr = merge_lst.end();
  itr--;                          // no math but -- or ++, only bi-directional iterators;
  merge_lst.insert(itr, "seen");  // insert before the iterator
  print_lst(cout, merge_lst) << endl;  
}
