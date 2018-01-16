#include<iostream>
using std::cout; using std::endl; using std::boolalpha;

/*
wfp 7/18/13
wfp updated 1/14/15
boolean operators
*/

int main(){
  bool bool_true=true, bool_false=false;
  long first=0, second=0;

  cout <<"bool_true:"<<bool_true<<", bool_false:"<<bool_false<<endl;
  cout << "Turning on boolalpha"<<boolalpha<<endl;
  cout <<"bool_true:"<<bool_true<<", bool_false:"<<bool_false<<endl;

  cout << "std  &&, bool_true && bool_false:"<< (bool_true && bool_false) << endl;
  cout << "alt and,  bool_true and bool_false:"<< (bool_true and bool_false) << endl;  

  cout << "std  ||, bool_true || bool_false:"<< (bool_true || bool_false) << endl;
  cout << "alt or,  bool_true and bool_false:"<< (bool_true or bool_false) << endl;    

  cout << "std  !, !bool_true:"<< !bool_true << endl;
  cout << "alt not,  not bool_true:"<<  not bool_true << endl; 

  // short circuiting and assignment return
  cout << "Short circuiting"<<endl;
  cout <<"first:"<<first<<", second:"<<second<<endl;
  (first = 100) || (second = 200);
  cout << "after  (first = 100) || (second = 200)"<<endl;
  cout <<"first:"<<first<<", second:"<<second<<endl;
  first = 0;
  second = 0;
  cout <<"first:"<<first<<", second:"<<second<<endl;
  cout << "after  (first = 0) && (second = 200)"<<endl;
  (first = 0) && (second = 200);
  cout <<"first:"<<first<<", second:"<<second<<endl;
  
}
