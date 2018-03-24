#include<iostream>
using std::cout; using std::cin; using std::endl;
#include<iomanip>
using std::boolalpha;
#include<string>
using std::string;
#include<stdexcept>
using std::runtime_error;

#include "lab10_circbuf.h"

int main(){
  cout << boolalpha;

  CircBuf cb(4);
  cout << boolalpha;
  cout << cb << endl;

  CircBuf cb_il({2,4,6,8}, 5);
  cout << cb_il << endl;

  try{
    CircBuf bad_il({2,4,6,8}, 4);
  }
  catch (runtime_error &e){
    cout << e.what() << endl;
  }
  
  cb.add(11);
  cb.add(12);
  cout << cb << endl;

  cout << "Front:" << cb.front() << endl;
  cout << "Back:" << cb.back() << endl;

  cb.remove();
  cout << "Front:"<<cb.front() <<endl;
  cb.remove();
  cout << "Empty?:"<< cb.empty() << endl;
  cout << "Full?:" << cb.full() << endl;
  

  cout << "Add 4 elements"<<endl;
  for(long i=0; i<4;i++)
    cb.add(i+27);
  cout << cb << endl;

  cout << "Remove 4 elements"<<endl;
  while(!cb.empty()){
    cb.remove();
  }

  cout << "Fill er up"<<endl;
  for(int i=0; !cb.full(); i++)
    cb.add(i*i);
  cout << "Full?:"<<cb.full() <<endl;

  // should throw, it's full
  try{
    cb.add(1111);
  }
  catch (runtime_error err){
    cout << err.what() << endl;
  }
  
  cout << "Drain it"<<endl;
  for(int i=0; !cb.empty(); i++)
    cb.remove();  
  cout << "Empty?:"<<cb.empty()<<endl;

  // should thow, it's empty
  try{
    cout << cb.front() << endl;
  }
  catch (runtime_error err){
    cout << err.what() << endl;
  }

  CircBuf cb2({1,2,3,4}, 5);
  cb2.add(20);
  cb2.remove();
  cb2.add(30);
  cb2.remove();
  cout << cb2 << endl;

  /*
  // Extra Credit
  cb = cb + 25;
  cb = 30 + cb;
  cout << cb << endl;
  cb = cb + cb;
  cout << cb << endl;
  */
}
