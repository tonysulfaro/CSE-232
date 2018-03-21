#include<string>
#include<sstream>
#include<cmath>
using std::string;
using std::ostringstream;

#include "lab09_vector.h"

//constructor for values
MathVector::MathVector(long x_value, long y_value){
	x = x_value;
	y = y_value;
}

//add vector
MathVector MathVector::add(const MathVector & other_vec){
	return(MathVector(x+other_vec.x,y+other_vec.y));
}

//multiply vector by scalars
MathVector MathVector::mult(long scalar){
	return MathVector(x*scalar,y*scalar);
}

//multiply vector by another vector
long MathVector::mult(const MathVector & vec){
	x*=vec.x;
	y*=vec.y;
	return x+y;
}

//magnitude of a vector using pythagorean
double MathVector::magnitude(){
	return(sqrt((x*x)+(y*y)));
}

// a function! You must write
// prints out the vector
string vec_to_str(const MathVector& v){
	ostringstream oss;
	oss << v.x << ":" << v.y;
	return oss.str();
}