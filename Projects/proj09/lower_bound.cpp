#include<iostream>
using std::cout; using std::endl;
#include<vector>
using std::vector;
#include<string>
using std::string; using std::to_string;
#include<algorithm>
using std::copy; using std::lower_bound;
#include<iterator>
using std::ostream_iterator;
#include<sstream>
using std::ostringstream;

// template on the vector type, more general purpose that way
// T type must be printable for this to work!
template<typename T>
string vector2string(vector<T> v){
  ostringstream oss;
  copy(v.begin(), v.end(), ostream_iterator<string>(oss, ","));
  string result = oss.str();
  // sloppy the comma at the end, get rid of it.
  return result.substr(0, result.size()-1);
}

int main (){
  // elements in alphabetical order, required for this to work!
  vector<string> v = {"alan", "bill", "fred", "john"};
  cout << vector2string(v) << endl;

  // points to fred, key just bigger than "doug"
  vector<string>::iterator itr = lower_bound(v.begin(), v.end(), "doug");
  cout << *itr << endl;
  // insert does so in front of the iterator, which *maintains sorted order*
  v.insert(itr, "doug");
  cout << vector2string(v) << endl;

  // points to "bill", lower_bound finds "not greater" than element.
  itr = lower_bound(v.begin(), v.end(), "bill");
  cout << *itr << endl;

  // itr points to begin(), "alan". inserts before itr, insert makes it the first element
  // maintains sorted order
  itr = lower_bound(v.begin(), v.end(), "abby");
  v.insert(itr, "abby");

  // itr points to end(), past "john". inserts before itr, insert makes it the last element
  // maintains sorted order
  itr = lower_bound(v.begin(), v.end(), "zach");
  v.insert(itr, "zach");

  cout << vector2string(v) << endl;

}
	    
