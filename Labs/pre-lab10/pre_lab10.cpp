#include<iostream>
using std::cout; using std::endl; using std::ostream;
#include<string>
using std::string; using std::to_string; 

class MyClass{
private:
  string s1_="";
  long l_=0;

public:
  MyClass()=default;                 // Line 1
  MyClass(long l, string s);
  void do_it(long);
  friend MyClass operator+ (const MyClass&, const MyClass&);
  friend ostream& operator<<(ostream&, const MyClass&);
};

MyClass::MyClass(long l, string s){
  l_ = l;
  s1_ = s + to_string(l);
}

void MyClass::do_it(long param_l){
  s1_ += to_string(param_l);
  l_ += param_l;
}

ostream& operator<<(ostream& o, const MyClass& c){
  o << c.s1_ << ":" << c.l_;
  return o;
}

MyClass operator+(const MyClass& c1, const MyClass& c2){
  string s;
  s = (c1.s1_ > c2.s1_) ? c1.s1_ + c2.s1_ : c2.s1_ + c1.s1_;
  return MyClass(c1.l_ + c2.l_, s);
}
  
int main(){
  MyClass mc1(3, "a");
  cout << mc1 << endl;                 // Line 2
  mc1.do_it(12);
  cout << mc1 << endl;                 // Line 3
  MyClass mc2(7, "c");
  MyClass mc3(5, "b");  
  cout << mc2 + mc3 << endl;           // Line 4
  MyClass mc4(9, "d");
  cout << mc4 + mc2 + mc3 << endl;     // Line 5
}

