// Let's assume I got the includes right
#include<iostream>
#include<string>
using std::string; using std::to_string;
#include<ostringstream>

string fn1(long *a, int s){
  ostringstream oss;
  copy(a, a+s, ostream_iterator<long>(oss, ", ") );
  string str = oss.str();
  return str.substr(0, str.size()-2);
}
long fn2(long a[], int s, long l){
  if (l >= s)
    throw out_of_range("array index:"+to_string(s)+" out of range");
  auto temp = *(a+l) * l;
  return temp;
}
long fn3(long *a, int s, long l){
  if (l >= s)
    throw out_of_range("array index:"+to_string(s)+" out of range");  
  auto temp = a[l] + l;
  return temp;
}
void fn4(long *a, int s, long *&b){
  b = new long[s];
  transform(a, a+s, b,
            [](long e){
              return e*e;
            }
            );
}    
int main (){       
  long a[]={1,2,3,4,5};
  int s = 5;

  cout << fn1(a,s) << endl;      // Line 1
  
  try{
    cout << fn2(a,s,3) << endl;  // Line 2
    cout << fn2(a,s,5) << endl;  // Line 3
  }
  catch(out_of_range &e){
    cout << e.what() << endl;
  }

  try{
    cout << fn3(a,s,4) << endl;  // Line 4
    cout << fn3(a,s,2) << endl;  // Line 5
  }
  catch(out_of_range &e){
    cout << e.what() << endl;
  }

  long *another;
  fn4(a,s,another);
  cout << fn1(another,s) << endl; // Line 6
}