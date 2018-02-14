#include<iostream>
using std::cout; using std::endl;
#include<string>
using std::string;

template <typename Type>
void f1 (Type &v1, Type &v2){
   Type t;
   t = v1;
   v1 = v2;
   v2 = t;
}

template<typename Type>
Type f2 (Type v1, long l){
// set t to a default value,
// the one appropriate for Type
   Type t = Type();
   for (int i=0;i<l;i++)
      t += v1;
   return t;
}

int main (){
   string s1="ayz", s2="xbc";
   f1(s1,s2);
   cout << s1 << endl;     // Line 1
   cout << f2(s1,3)<<endl; // Line 2

   long l1=20, l2=10;
   f1(l1, l2);
   cout << l1 << endl;       // Line 3
   cout << f2(l1,3)<<endl;   // Line 4

// cout << f1(l1,l2) << endl; // Line 5
// cout << f2(l1,s1) << endl; // Line 6
}
