#ifndef VECTOR_H
#define VECTOR_H

#include<string>
using std::string;

struct MathVector{
  // data members, default public
  long x=0;
  long y=0;

  // 2 constructors
  // =default uses default values of data members (above).
  // no other work required. You're welcome!
  MathVector()=default;
  // you must write
  MathVector(long, long);

  // 4 function members you must write
  MathVector add (const MathVector&);
  MathVector mult(long);
  long mult(const MathVector&);
  double magnitude();
};

// a function! You must write
string vec_to_str(const MathVector&);


#endif
