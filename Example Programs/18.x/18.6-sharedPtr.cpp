#include<memory>
using std::shared_ptr; using std::unique_ptr;
#include<iostream>
using std::cout; using std::endl;

/*
  wfp 3/18/15
  using C++11 shared pointers
*/

int main (){
  int reps = 2048;
  const size_t chunk = 1048576; // be careful!!!
  long temp = 0;

  for(int i=0;i<reps;i++){
    // unique pointer, only one owner. Destroyed automatically
    unique_ptr<long[]> shared_ary(new long[chunk]);
    // shared_ptr. destroyed when last owner lets it go
    // required a deleter for an array
    // shared_ptr<long> shared_ary(new long[chunk],
    // 			 [] (long *p){
    // 				  cout <<"deleting"<<",";
    // 				  delete [] p;
    // 				});

    // get the underlying element.
    long *ary = shared_ary.get();
    for (int j=1;j<chunk;j++)
      ary[j] = ary[j-1] + temp;
    temp = ary[chunk-1];
  }
}
